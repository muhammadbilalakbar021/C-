DoctorSchedule::DoctorSchedule(int num_appointment)
{
  // Make sure that the constructor initializes the following data members:
  // initialize `num_appointments_` to the variable passed in
  // initialize `appointment_` to a dynamically allocated array of `Appointment`
  // objects whose size is based on `num_appointment`

  for (/* control the loop so it goes through all appointments */) {
    std::string name, location, time;
    std::cout << "Who is this appointment with?: ";
    std::getline(std::cin, name);
    std::cout << "Where is this appointment?: ";
    std::getline(std::cin, location);
    std::cout << "What time is this appointment?: ";
    std::getline(std::cin, time);

    // Create an `Appointment` object according to the user input

    // Set the appointment at this index of the array.

    std::cout << "\n\n";
  }

  // Initiatlize `current_appointment_num_` to ensure it is the first
  // appointment.

}
