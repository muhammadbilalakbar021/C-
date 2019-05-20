int main()
{
  // Create an array of 100 `Athlete` objects called `athlete`

  // Create an `Athlete` object called `temp_athlete`

  std::string name, sport, style, color;
  double size;
  int height, weight, num_athletes = 0;

  do {
    std::cout << "Please enter the athlete's sport (q to quit): ";
    std::getline(std::cin, sport);
    if (sport == "q") {
      continue;
    }

    std::cout << "Please enter the athlete's name: ";
    std::getline(std::cin, name);
    std::cout << "Please enter the athlete's height (in): ";
    std::cin >> height;
    std::cout << "Please enter the athlete's weight (lbs): ";
    std::cin >> weight;
    std::cout << "Please enter the shoe style: ";
    std::cin.ignore();
    std::getline(std::cin, style);
    std::cout << "Please enter the shoe color: ";
    std::getline(std::cin, color);
    std::cout << "Please enter the shoe size (in): ";
    std::cin >> size;
    std::cin.ignore();

    // Dynamically allocate an `AthleticShoe` object using the user's
    // input and store the location into a pointer called `shoe`

    // Use the rest of the user's input to update the values of the
    // `temp_athlete` object

    // Store the `temp_athlete` object inside the `athlete` array.
    // Don't forget to update your index so that the next object is
    // stored in the correct location.

  } while (sport != "q");

  std::cout << "Printing Athletes:\n";

  for (int i = 0; i < num_athletes; i++) {
    std::cout << "Athlete " << i + 1 << "\n";

    // Display information about each `Athlete` object in `athlete` using
    // the `print` member function.

  }

  return 0;
}
