#include <algorithm>
#include <gtkmm.h>
#include <iostream>
#include <vector>

void assignment1();

class Window : public Gtk::Window {
public:
  Gtk::Box box;
  Gtk::Entry firstName;
  Gtk::Entry lastName;
  Gtk::Button button;
  Gtk::Label label;

  Window() : box(Gtk::Orientation::ORIENTATION_VERTICAL) {
    button.set_label("Combine name");

    box.pack_start(firstName);
    box.pack_start(lastName);
    box.pack_start(button); // Add the widget button to box
    box.pack_start(label);  // Add the widget label to box

    add(box);   // Add vbox to window
    show_all(); // Show all widgets

    firstName.signal_activate().connect([this]() {
      label.set_text("Entry activated");
    });

    button.signal_clicked().connect([this]() {
      label.set_text("Combined name: " + firstName.get_text() + " " + lastName.get_text());
    });
  }
};

int main() {

  assignment1();

  auto app = Gtk::Application::create();
  Window window;
  return app->run(window);
}

void assignment1() {

  std::vector<int> nums{1, 2, 3, 4, 6};

  std::cout << nums.front() << "\n";
  std::cout << nums.back() << "\n";

  std::cout << "\n";

  nums.emplace(nums.begin() + 4, 5);

  for (auto i : nums) {
    std::cout << i << "\n";
  }

  std::cout << "\n";

  auto it = find(nums.begin(), nums.end(), 7);

  if (it != nums.end()) {
    std::cout << distance(nums.begin(), it + 1) << "\n";

  } else {
    std::cout << "\nIkke funnet\n";
  }
}
