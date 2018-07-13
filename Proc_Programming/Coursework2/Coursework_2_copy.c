#include <stdio.h>

/******************************************************************** GLOBAL VARIABLES ************************************************************/
#define max_patient 15
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
// returns the patient queue position

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

int patient_position(int id_number)
{
    int p_position = -1, p_index;
    p_index = patient_index(id_number);
    if (p_index == -1) return p_position = - 1;
    if (p_index >= first) p_position = p_index - first + 1;
    else p_position = max_patient - first + p_index + 1;
    return p_position;    
}
// find free or patient in doctor room
int doctor_room_status(int room_val)
{
    int i;
    for (i = 0; i <= (max_room - 1); i = i + 1)
    {
        if (doctor_room[i] == room_val) return (i+1);
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
void printdoctor()
{
    int i, doctor_count, print_room;
    doctor_count = 0;
    for (i = 0; i <= (max_room - 1); i = i + 1)
    {
        if (doctor_room[i] > 0) doctor_count = doctor_count + 1;
    }
    if (doctor_count > 0)
    {
        printf("There are currently %d doctors in the surgery. They are in rooms ", doctor_count);
        for (i = 0; i <= (max_room - 1); i = i + 1)
        {
            if (doctor_room[i] > 0)
            {
                print_room = print_room + 1;
                if (print_room == 1) printf("%d", i+1);
                else if (print_room == doctor_count) printf(", and %d", i+1);
                else printf(", %d", i+1);
            }
        }
        printf("\n");
    }
    else printf("There is no any doctor in the surgery right now!\n");
}
// find free or patient in doctor room
int doctor_room_status(int room_val)
{
    int i;
    for (i = 0; i <= (max_room - 1); i = i + 1)
    {
        if (doctor_room[i] == room_val) return (i+1);
    }
    return -1;    
}
void printdoctor()
{
    int i, doctor_count, print_room;
    doctor_count = 0;
    for (i = 0; i <= (max_room - 1); i = i + 1)
    {
        if (doctor_room[i] > 0) doctor_count = doctor_count + 1;
    }
    if (doctor_count > 0)
    {
        printf("There are currently %d doctors in the surgery. They are in rooms ", doctor_count);
        for (i = 0; i <= (max_room - 1); i = i + 1)
        {
            if (doctor_room[i] > 0)
            {
                print_room = print_room + 1;
                if (print_room == 1) printf("%d", i+1);
                else if (print_room == doctor_count) printf(", and %d", i+1);
                else printf(", %d", i+1);
            }
        }
        printf("\n");
    }
    else printf("There is no any doctor in the surgery right now!\n");
}
/******************************************************************** MAIN FUNCTIONS ************************************************************/
int main()
{
    //set the variables
    char service_command, s_command[5];
    int service_choice, service_stop, password, patient_id, p_position, patient_index, room_number, command_id;

    // password for administrator
    //password = 1234;
    service_stop = 0;

    // initialise the queue and room
    clear();

    while (service_stop == 0)
    {
        printf("Welcome to the hospital.\n");
        printf("Enter your command and id\n");
        printf(">>>");
        //scanf(" %c%i", &service_command, &command_id);
        scanf(" ");
        gets(s_command);
        sscanf(s_command, "%c%d", &service_command, &command_id);

        if ((command_id == 0) & (service_command == 'i' || service_command == 'p' || service_command == 'q' || service_command == 'o' || service_command == 'r' || service_command == 'a'))
        {
            printf("Invalid command. Please enter 'h' without qoute for help.\n");
            continue;
        }
            
        if (service_command == 'o' || service_command == 'r' || service_command == 'a' || service_command == 'w' || service_command == 'x')
        {
            printf(">>>Please enter your password: ");
            scanf(" %d", &password);
            // check for password
            if (password != 1234)
            {
                printf("You enter wrong password!\n");
                continue;
            }
        } // if the password is correct run the doctor commands
        
        switch (service_command)
        {
            // the i command
            case('i'):
                patient_id = command_id;
                p_position = patient_position(patient_id);
                if (p_position != -1)
                {
                    printf("You are already checked in! Your are in position %d in the queue.\n", p_position);
                    break;
                }
                room_number = doctor_room_status(patient_id);
                if (room_number != -1)
                {
                    printf("Patient %d are meeting with doctor in room %d.\n", patient_id, room_number);
                    break;
                }
                printf("Welcome to patient %d\n", patient_id);
                room_number = doctor_room_status(1);
                if (room_number != -1) 
                {
                    printf("Please proceed to Room %d\n", room_number);
                    doctor_room[room_number-1] = patient_id;
                }
                else
                {
                    enqueue(patient_id);
                }
                break;
            // the p command
            case('p'):
                patient_id = command_id;
                p_position = patient_position(patient_id);
                if (p_position != -1) printf("You are in position %d in the queue.\n", p_position);
                else printf("You are not in queue.\n");
                break;
            // the q command
            case('q'):
                patient_id = command_id;
                remove_patient(patient_id);
                break;
            // the d command
            case('d'):
                printdoctor();
                break;
            // the h command
            case('h'):
                printf("The 'i' command is for checking in\n");
                printf("The 'p' command is for checking your position in the queue\n");
                printf("The 'q' command is for checking out if you don't want to see a doctor\n");
                printf("The 'd' command is for checking how many doctors are available, and which room they are at\n");
                break;
            // the o command
            case('o'):
                patient_id = command_id;
                room_number = doctor_room_status(patient_id);
                if (room_number == -1) printf("Patient %d is not in any room\n", patient_id);
                else 
                {
                    doctor_room[room_number-1] = 2;
                    printf("Patient %d has been successfully discharged\n", patient_id);
                }
                break;
            // the r command
            case('r'):
                room_number = command_id;
                if ((room_number <= (max_room)) & (room_number > 0))
                {
                    if (doctor_room[room_number-1] > 2)
                    {
                        printf("Is the patient %d still in the room?\n", doctor_room[room_number-1]);
                        printf("Check this patient out before calling on another one\n");
                    }
                    else
                    {
                        patient_id = dequeue();
                        if (patient_id != -1) 
                        {
                            printf("Patient %d, please go to Room %d.\n", patient_id, room_number);
                            doctor_room[room_number-1] = patient_id;
                        }
                        else doctor_room[room_number-1] = 1;
                    }
                }
                else printf("You enter wrong room number! The room number should be from 1 to 10.\n");
                break;
            // the a command
            case('a'):
                room_number = command_id;
                if ((room_number <= (max_room)) & (room_number > 0))
                {
                    if (doctor_room[room_number-1] > 2)
                    {
                        printf("Is the patient %d still in the room?\n", doctor_room[room_number-1]);
                        printf("Check this patient out first\n");
                    }
                    else doctor_room[room_number -1] = 0;
                }
                else printf("You enter wrong room number! The room number should be from 1 to 10.\n");
                break;
            // the w command
            case('w'):
                print();
                break;
            // the x command
            case('x'):
                service_stop = 1;
                break;
            default:
                printf("Invalid command. Please enter 'h' without qoute for help.\n");
            }
    }
}