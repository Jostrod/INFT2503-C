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
    button.set_sensitive(false);

    box.pack_start(firstName);
    box.pack_start(lastName);
    box.pack_start(button);
    box.pack_start(label);
    add(box);
    show_all();

    firstName.signal_changed().connect([this]() {
      if (!lastName.get_text().empty() && !(firstName.get_text().empty())) {
        button.set_sensitive(true);
      } else {
        button.set_sensitive(false);
      }
    });

    lastName.signal_changed().connect([this]() {
      if (!firstName.get_text().empty() && !lastName.get_text().empty()) {
        button.set_sensitive(true);
      } else {
        button.set_sensitive(false);
      }
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
  window.set_title("Øving 4 - Oppgave2");
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
