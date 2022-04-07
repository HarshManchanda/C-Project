1.	addis() : This function can be manipulated to add further places and distances, flight time between them.
It stores the data in “places.dat” in binary format.

2.	showdis() : This function shows the data of “places.dat” in tabular form

3.	writeseats() : Resets the number of seats in each flight from the file “seats.dat”,
In case of any failure or error in booking tickets, the programmer can use this function to reset the seats.

4.	modifyseats() : Increases or decreases the number of seats in a particular fight number of a particular class ( Business / Economy ) and writes the data into the file “seats.dat”.

5.	showseats() : Displays the number of available seats in each flight number in tabular form.

6.	checkseats() : Returns the number of seats available in a particular flight number and class ( Business / Economy ).

7.	allotres() : Returns the next reservation number from the last record pf “myflight.dat” by adding 1 to it.
8.	calprice() : Sets the price of the ticket by checking the type ( domestic / international ) and class ( business / economy ) and distance between the location and destination.
There is an option to set the flight time of the ticket too.

9.	getf() : It gets all the data for the flight from the passenger and displays his / her ticket.

10.	getpasinfo() : It gets the passenger’s information from the user.

11.	modifyinfo() : Modifies the passenger’s details if the ticket is confirmed from both the files “conflights.dat” nad “myflight.dat”.

12.	showf() : Dispalys the ticket for the passengers.

13.	writefile() : Writes the data of the ticket in “myflight.dat” and “conflights.dat” in binary format.

14.	canceltic() : It deletes the record of the passenger from “conflights.dat”.
Also, it changes the status of the record from “CONFIRMED” to “UNCONFIRMED” and writes it back to file “myflight.dat” instead of deleting it.
15.	showtic() : Takes the reservation number from the user and displays that the user’s ticket is confirmed.

16.	verify() : Asks the user to enter administrator password and returns 0 if password is correct.

17.	showfile() : Display all the records in “myflight.dat”.

18.	countrec() : Returns the number of tickets in a file by taking the file name as an argument.

19.	showt() : Display all the tickets in tabular form of their reservation number.
