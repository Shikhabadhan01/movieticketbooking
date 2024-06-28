#include <stdio.h>
#include <string.h>

#define MAX_SEATS 50

// Structure to represent user data
struct UserData {
    char name[50];
    char phone[15];
    int seat_number;
};

// Structure to represent a seat
struct Seat {
    int seat_number;
    char is_booked;
    struct UserData user;
};

// Function to initialize the seats
void initializeSeats(struct Seat seats[], int num_seats) {
    for (int i = 0; i < num_seats; i++) {
        seats[i].seat_number = i + 1;
        seats[i].is_booked = 0;
    }
}

// Function to display the seat map
void displaySeatMap(struct Seat seats[], int num_seats) {
    printf("Seat Map:\n");
    for (int i = 0; i < num_seats; i++) {
        if (seats[i].is_booked) {
            printf("[X] "); // Booked seat
        } else {
            printf("[%d] ", seats[i].seat_number);
        }
        if ((i + 1) % 10 == 0) {
            printf("\n");
        }
    }
}

// Function to book a seat
void bookSeat(struct Seat seats[], int num_seats, int seat_number, struct UserData *user) {
    if (seat_number < 1 || seat_number > num_seats) {
        printf("Invalid seat number.\n");
        return;
    }

    if (seats[seat_number - 1].is_booked) {
        printf("Seat %d is already booked.\n", seat_number);
        return;
    }

    seats[seat_number - 1].is_booked = 1;
    seats[seat_number - 1].user = *user;
    user->seat_number = seat_number;
    printf("Seat %d is booked successfully!\n", seat_number);
}

// Function to generate a bill
void generateBill(struct UserData user) {
    printf("----- Booking Details -----\n");
    printf("Name: %s\n", user.name);
    printf("Phone Number: %s\n", user.phone);
    printf("Seat Number: %d\n", user.seat_number);
    printf("Ticket Price: $10.00\n"); // You can adjust the ticket price
    printf("Total Amount: $10.00\n"); // Total price calculation can be added here
    printf("Enjoy the movie!\n");
}

int main() {
    struct Seat seats[MAX_SEATS];
    int num_seats = MAX_SEATS;

    initializeSeats(seats, num_seats);

    while (1) {
        printf("\n1. Display Seat Map\n");
        printf("2. Book a Seat\n");
        printf("3. Quit\n");

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displaySeatMap(seats, num_seats);
                break;
            case 2:
                struct UserData user;
                printf("Enter your name: ");
                scanf("%s", user.name);
                printf("Enter your phone number: ");
                scanf("%s", user.phone);
                printf("Enter the seat number you want to book: ");
                int seat_number;
                scanf("%d", &seat_number);
                bookSeat(seats, num_seats, seat_number, &user);
                generateBill(user);
                break;
            case 3:
                printf("Thank you for using our service!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}