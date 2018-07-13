/********************************************************************

I declare that the following program was written by me and that I have NOT copied any part of this code from any other source.

Name: Minh Hien Pham

Email: sc17mp@leeds.ac.uk

Date: 13/11/2017

*********************************************************************/
#include <stdio.h>
/******************************************************************** GLOBAL VARIABLES ************************************************************/
#define max_patient 60
#define max_room 10
int patient_queue[max_patient], first, last;
int doctor_room[max_room];
#define bool int
#define True 1
#define False 0

/******************************************************************** INT FUNCTIONS ************************************************************/
// checks if the queue is full
int IsFull()
{
    if ((first == 0 && last == (max_patient - 1)) || first == last + 1)  return 1;
    else return 0;
}
// checks if the queue is empty
int IsEmpty()
{
    if (first == -1 && last == -1) return 1;
    else return 0;
}
// returns the index of an id number
int patient_index(int id_number)
{
    int p_index = -1, i;
    if (IsEmpty())
    {
        return p_index;
    }
    for(i = 0; i<=max_patient - 1; i++)
    {
        if (patient_queue[i] == id_number)
        {
            p_index = i;
            if (first <=last) if(p_index >=first && p_index <= last) return p_index;                    
            else if (first > last)
            {
                if (p_index >= first && p_index <=max_patient - 1) return p_index;                    
                else if (p_index >= 0 && p_index <= last) return p_index;                    
            }
        }
    }
    return p_index; 
}
// returns the first position value in the queue
int first_position(int patient_queue[])
{
    if (IsEmpty()) return -1;
    else return patient_queue[first];
}
// returns the last position value in the queue
int last_position(int patient_queue[])
{
    if (IsEmpty()) return 0;
    else return patient_queue[last];
}

//dequeueing the patient in the first position when a doctor calls
int dequeue()
{
    int id_number;
    // if the queue is empty
    if (IsEmpty()) return -1;
    // return the first position value
    id_number = patient_queue[first];
    // if there is only one patient in the queue
    if (first == last) first = last = -1;
    // if there is more than one patients in the queue
    else
    {
        if (first == max_patient - 1) first = 0;
        // if the queue is neither full nor empty
        else first = first + 1;
    }
    return id_number;
}

// returns the patient queue position
int patient_position(int id_number)
{
    int p_position = -1, p_index;
    p_index = patient_index(id_number);
    if (p_index == -1) return p_position = - 1;
    if (p_index >= first) p_position = p_index - first + 1;
    else p_position = max_patient - first + p_index + 1;
    return p_position;    
}
// find free doctor or patient in doctor room
int doctor_free(int room_value)
{
    int i;
    for (i = 0; i <= (max_room - 1); i++)
    {
        if (doctor_room[i] == room_value) return (i+1);
    }
    return -1;    
}
/******************************************************************** VOID FUNCTIONS ************************************************************/
// initialises the queue
void clear()
{
    first = -1;
    last = -1;
    int i;
    for(i = 0; i <= max_room - 1; i++)
    doctor_room[i] = 0;
}

// queues the patient
void enqueue(int id_number)
{
    int position;
    // if the queue is full
    if (IsFull())
    {
        printf("The queue is full. Please wait.\n");
        return;
    }
    //if the queue is not full
    else
    {
      if (IsEmpty()) first = last = 0;
      else
      {
          if (last == max_patient - 1)
          {
              last = 0;
          }
          else
          {
              last = last + 1;
          }
      }
      // queue the patient to the last index
      patient_queue[last] = id_number;
      if (last >= first)
      {
          position = last - first + 1;
      }
      else
      {
          position = (max_patient - 1) - first + 1 + (last + 1);
      }
    printf("Please relax in the waiting area. You are position %i in the queue\n", position);      
    }
}
void remove_patient(int id_number)
{
    int p_index, i;
    if (IsEmpty())
    {
        printf("The queue is empty\n");
        return;
    }
    p_index = patient_index(id_number);// get the index of the remove id  
    // if the queue is not empty  
    if (p_index == -1) printf("You are not in the queue.\n");   
    else
    {
        // if index of id is smaller than index of last
        if(p_index < first)
        {
            for(i = p_index; i<=last-1; i++)
            {
                patient_queue[i] = patient_queue[i+1];
            }
            if(last == 0) last = max_patient - 1;
            else last = last - 1;
        }
       else
       {
            // if the queue wraps around
            if (first > last)
            {
                for (i = p_index; i <=max_patient - 1; i++)
                {
                    patient_queue[i] = patient_queue[i+1];
                }
                patient_queue[max_patient - 1] = patient_queue[0];                                       
                for (i = 0; i <= last - 1; i++)
                {
                    patient_queue[i] = patient_queue[i+1];
                }
                if(last == 0) last = max_patient - 1;                    
                else last = last - 1;                                
            }
            // if the queue doesn't wrap around
            else
            {
                for(i = p_index; i <= last - 1; i++)
                {
                    patient_queue[i] = patient_queue[i+1];
                }
                if(last == first) first = last = -1;
                else if(last == 0) last = max_patient - 1;                  
                else last = last - 1;        
            }
        }
        printf("You have been remove from the queue.\n");        
    }
}
void print()
{
    int i, id_number;
    if (IsEmpty()) printf("There is no patient here yet.\n");    
    else
    {
        printf("The following patient are still waiting to see a doctor:\n");
        if(last >= first)
        {
           for(i = first; i <= last; i++)
            {
                if (i == last) printf("%i\n", patient_queue[i]);
                else printf("%i, ", patient_queue[i]);
            }
        }
        else
        {
            for(i = first; i<=max_patient -1; i++)
            {
                printf("%i, ", patient_queue[i]);
            }
            for(i = 0; i <= last; i++)
            {
                if (i == last) printf("%i\n", patient_queue[i]);
                else printf("%i, ", patient_queue[i]);
            }
        }
    }
}
/******************************************************************** MAIN FUNCTIONS ************************************************************/
int main()
{
    //set the variables
    char letter_command, service_command[5];
    int service_choice, service_stop, password, command_id, i, p_position, patient_id, room, doctor_available, room_count;

    // password for administrator
    password = 1234;
    service_stop = 0;

    // initialise the queue
    clear();

    while (service_stop == 0)
    {
        printf("Welcome to the hospital.\n");
        printf("Enter your command and id/room number\n");
        printf(">>>");
        scanf(" ");
        gets(service_command);
        // scans both the command and the number
        sscanf(service_command, " %c%i", &letter_command, &command_id); 
        
        // command for doctors that requires password
        if(letter_command == 'o' || letter_command == 'r' || letter_command == 'a' || letter_command == 'w' || letter_command == 'x')
        {
            printf("Please enter password\n");
            printf(">>>");
            scanf(" %i", &password);
            if(password != 1234)
            {
                printf("Invalid password, try again.\n");
                continue;
            }
        }// if password is correct, run the doctor commands
            switch (letter_command)
            {
                // the i command
                case('i'):
                    patient_id = command_id;
                    p_position = patient_position(patient_id);
                    i = room - 1;
                    // if the patient is already in the queue
                    if (p_position != -1)
                    {
                        printf("You already check in. You are position %i in the queue.\n", p_position);
                        break;
                    }
                    // if there is a doctor available
                    if (doctor_room[i] == 1)
                    {
                        doctor_room[i] = patient_id;                        
                        printf("Please proceed to room %i,", room);
                    }
                    // if the patient is in a room
                    if (doctor_room[i] > 2)
                    {
                        printf("Patient %i is in the room %i", patient_id, room);
                    }
                    // if there is no doctor available
                    else enqueue(patient_id);   
                    break;
                // the p command
                case('p'):
                    p_position = patient_position(patient_id);
                    printf("You are position %i in the queue\n",p_position);
                    break;
                // the q command
                case('q'):
                    patient_id = command_id;                
                    remove_patient(patient_id);
                    break;
                // the d command
                case('d'):
                    doctor_available = 0;
                    room_count = 0;
                    room = i + 1;
                    // count the number of doctors
                    for(i = 0; i <=max_room - 1; i++)
                    {
                        if(doctor_room[i] >  0) 
                        doctor_available = doctor_available + 1;
                    }
                    if (doctor_available > 0)
                    {
                        printf("There are %i doctors available.", doctor_available); 
                        // finding which room they are in                                           
                        for(i =0; i <=max_room -1; i++)
                        {
                            room_count = room_count + 1;
                        }
                        if (room_count == 1) printf("They are in rooms %i", room);
                        else if (room_count == doctor_available) printf(", and %i", room);
                        else printf(", %i", room);
                    }
                    else printf("There are no doctors in the surgery right now.\n");
                    break;
                // the h command
                case('h'):
                    printf("The commands for patients are:\n\n");
                    printf("The 'i' command is for checking in\n");
                    printf("The 'p' command is for checking your position in the queue\n");
                    printf("The 'q' command is for checking out if you don't want to see a doctor\n");
                    printf("The 'd' command is for checking how many doctors are available, and which room they are at\n");
                    printf("The commands for administrators and doctors are:\n\n");
                    printf("The 'o' command is for doctor to check out a patient\n");
                    printf("The 'r' command is for doctor to call a patient or to tell they're available.\n");
                    printf("The 'a' command is for doctor to check themselves out of the room.\n");
                    printf("The 'w' command is for doctor to see which patients are still waiting.\n");
                    printf("The 'x' command is for doctor to quit the programm, when the surgery closes\n");
                break;
                //the o command
                case('o'):
                    room = command_id;
                    i = room - 1;
                    if(room == -1) printf("Patient %i is not in any room.\n", patient_id);
                    else
                    {
                        doctor_room[i] = 2;
                    }
                printf("Patient check out successful\n");
                break;
                // the r command
                case('r'):
                    patient_id = dequeue();
                    break;
                // the a command
                case('a'):
                    patient_id = command_id;
                    i = room - 1;
                    if(room > 0 && room <=10)
                    {
                        if(patient_id == doctor_room[i]) printf("Is the patient still inside the room? Check them out before.\n");
                        else doctor_room[i] = 0;
                    }
                    else printf("Invalid room number. Please enter room number from 1 - 10.\n");
                    break;
                // the w command
                case('w'):
                    print();
                    break;
                // the x command
                case('x'):
                    service_stop = 1; // quits the program
                    printf("You have quit the service.\n");
                    break;
                default: 
                    printf("Invalid command. Enter h if you need help.\n");
                    break;
            }
    } 
    return 0;         
}