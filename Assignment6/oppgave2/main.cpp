#include <boost/asio.hpp>
#include <iostream>

using namespace std;
using namespace boost::asio::ip;

class WebServer {
private:
  class Connection {
  public:
    tcp::socket socket;
    Connection(boost::asio::io_context &io_context) : socket(io_context) {}
  };

  boost::asio::io_context io_context;

  tcp::endpoint endpoint;
  tcp::acceptor acceptor;

  void handle_request(shared_ptr<Connection> connection) {
    auto read_buffer = make_shared<boost::asio::streambuf>();
    // Read from client until newline ("\r\n")
    async_read_until(connection->socket, *read_buffer, "\r\n", [this, connection, read_buffer](const boost::system::error_code &ec, size_t) {
      // If not error:
      if (!ec) {
        // Retrieve message from client as string:
        istream read_stream(read_buffer.get());
        std::string message;
        getline(read_stream, message);
        message.pop_back(); // Remove "\r" at the end of message

        istringstream request_stream(message);
        string method;
        string path;

        string status;
        string body;

        auto write_buffer = make_shared<boost::asio::streambuf>();
        ostream write_stream(write_buffer.get());

        request_stream >> method >> path;

        if (method == "GET" && path == "/") {
          status = "200 OK";
          body = "Dette er hovedsiden";
        } else if (method == "GET" && path == "/en_side") {
          status = "200 OK";
          body = "Dette er en side";
        } else {
          status = "404 Not Found";
          body = "404 ERROR";
        }

        cout << "Message from a connected client: " << message << endl;

        write_stream << "HTTP/1.1 " << status << "\r\n"
                     << "Content-Length: " << body.size() << "\r\n"
                     << "\r\n"
                     << body;

        // Write to client
        async_write(connection->socket, *write_buffer, [this, connection, write_buffer](const boost::system::error_code &ec, size_t) {
          // If not error:
          if (!ec)
            handle_request(connection);
        });
      }
    });
  }

  void accept() {
    // The (client) connection is added to the lambda parameter and handle_request
    // in order to keep the object alive for as long as it is needed.
    auto connection = make_shared<Connection>(io_context);

    // Accepts a new (client) connection. On connection, immediately start accepting a new connection
    acceptor.async_accept(connection->socket, [this, connection](const boost::system::error_code &ec) {
      accept();
      // If not error:
      if (!ec) {
        handle_request(connection);
      }
    });
  }

public:
  WebServer() : endpoint(tcp::v4(), 8080), acceptor(io_context, endpoint) {
  }

  void start() {
    accept();

    io_context.run();
  }
};

int main() {
  WebServer web_server;

  cout << "Starting web server" << endl
       << "Connect in a terminal with: telnet localhost 8080. Type 'exit' to end connection." << endl;

  web_server.start();
}
