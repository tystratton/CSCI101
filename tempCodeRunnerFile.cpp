            if (reservations[i].checkedIn == false) {
                    cout << i + 1 << ": " << reservations[i].name << " - " << reservations[i].time
                        << ", " << reservations[i].partyNum << " people" << endl;
                } else {
                    continue; // Skip this iteration if the reservation is already checked in
                }
            }