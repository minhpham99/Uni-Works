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
    if ((first == 0 && last == (max_patient -1)) || first == last + 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
// checks if the queue is empty
int IsEmpty()
{
    if (first == -1 && last == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
// returns the index of an id number
int patient_index(int id_number)
{
    int index = -1, i;
    for(i = 0; i<=max_patient - 1; i++)
    {
        if (patient_queue[i] == id_number)
        {
            index = i;
            if (index >= first || index <=last)
            {
                return index;
            }
        }
    }
}
// returns the first position value in the queue
int first_position(int patient_queue[])
{
    if (IsEmpty())
    {
        return -1;
    }
    else
    {
        return patient_queue[first];
    }
}
// returns the last position value in the queue
int last_position(int patient_queue[])
{
    if (IsEmpty())
    {
        return 0;
    }
    else
    {
        return patient_queue[last];
    }
}
// returns the patient queue position

//dequeueing the patient in the first position when a doctor calls
int dequeue()
{
    int id_number, i;
    // if the queue is empty
    if (IsEmpty())
    {
        return -1;
    }
    // return the first position value
    id_number = patient_queue[first];
    id_number = patient_queue[i];
    // if there is only one patient in the queue
    if (first == last)
    {
        first = last = -1;
    }
    // if there is more than one patients in the queue
    else
    {
        if (first == max_patient - 1)
        {
            first = 0;
        }
        // if the queue is neither full nor empty
        else
        {
            first = first + 1;
        }
    }
    return id_number;
}

int patient_position(int id_number)
{
    int p_position = -1, index;
    index = patient_index(id_number);
    if (index >= first && index <= last)
    {
        p_position = index - first + 1;
        return p_position;
    }
    else if (index >= first && index <= max_patient - 1)
    {
        p_position = index - first + 1;
        return p_position;

    }
    else
    {
        p_position = max_patient - first + index + 1;
        return p_position;
    }
}
/******************************************************************** VOID FUNCTIONS ************************************************************/
// initialises the queue
void clear()
{
    first = -1;
    last = -1;
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
      if (IsEmpty())
      {
          first = last = 0;
      }
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
      printf("Please relax in the waiting area.\nYou are position %i in the queue\n", position);
    }
}
void remove_patient(int id_number)
{
    int position, id_index, i, first_value, last_value;
    if (IsEmpty())
    {
        printf("The queue is empty\n");
    }
    // if the queue is not empty
   else
   {
        id_index = patient_index(id_number);// get the index of the remove id
        first_value = patient_queue[first];// return the first value
        last_value = patient_queue[last];// return the last value
        first = patient_index(first_value);// returns the first value index
        last = patient_index(last_value);// returns the last value index
        // if index of id is larger than index of first
        if(id_index <= first)
        for(i = id_index; i<last - 1; i++)
       {
           if(patient_queue[i] == id_number)
           {
                patient_queue[i] = patient_queue[i+1];
           }
           last = last - 1;
       }
       // if index of id is smaller than index of first
       else if(id_index >= first)
       {
            // if the queue wraps around
            if(first > last)
            {
                for(i = id_index; i < max_patient - 1; i++)
                {
                    {
                        patient_queue[i] = patient_queue[i+1];
                    }
                }
                for( i = 0; i < last - 1; i++)
                {
                    if(patient_queue[i] == id_number)
                    {
                      patient_queue[i] = patient_queue[i+1];
                    }
                    else if(patient_queue[i] == patient_queue[max_patient - 1]) // k chay vao
                    {
                        patient_queue[0] = patient_queue[i];
                    }
                }
              }
                // if the queue doesn't wrap around
                else
                  {
                        for(i = id_index; i < last - 1; i++)
                        {
                            patient_queue[i] = patient_queue[i+1];
                        }
                        last = last - 1;
                  }
            }
       }
}
void print()
{
    int i, id_number;
    if (IsEmpty())
    {
        printf("There is no patient here yet.\n");
        if(patient_queue[i]!= id_number)
        {
            printf("The patient is not in the queue.\n");
        }
    }
    else
    {
        printf("The following patient are still waiting to see a doctor:\n");
        if(last > first)
        {
           for(i = first; i <= last; i++)
            {
                if (i == first)
                printf("%i(first),", patient_queue[i]);
                else if (i == last)
                printf("%i(last)\n", patient_queue[i]);
                else
                printf("%i, ", patient_queue[i]);
            }
        }
        else
        {
            for(i = first; i<=max_patient -1; i++)
            {
                if (i == first)
                printf("%i,(first)", patient_queue[i]);
                else
                printf("%i, ", patient_queue[i]);
            }
            for(i = 0; i <= last; i++)
            {
                if (i == last)
                printf("%i(last)\n", patient_queue[i]);
                else
                printf("%i, ", patient_queue[i]);
            }
        }
    }
}

/******************************************************************** MAIN FUNCTIONS ************************************************************/
int main()
{
    //set the variables
    char service_command, service_stop;
    int service_choice, password, patient_id, i, position, index, room, doctor_available = 0, position_index;

    // password for administrator
    password = 1234;
    service_stop = 0;

    // initialise the queue
    clear();

    while (service_stop == 0)
    {
        printf("Welcome to the hospital.\n");
        printf("Enter 1 for patient or 2 for administrator:\n");
        printf(">>>");
        scanf(" %i", &service_choice);

        if (service_choice == 1)
        {
            printf("Enter your command and id\n");
            printf(">>>");
            scanf(" %c %i", &service_command, &patient_id);
            switch (service_command)
            {
                case('i'):
                i = room;
                if(doctor_room[i] == 1)
                    {
                        doctor_room[i] = patient_id;
                        printf("Please proceed to room %i\n", room = i+1);
                    }
                else
                {
                    enqueue(patient_id);
                }
                break;
                case('p'):
                position = patient_position(patient_id);
                position_index = patient_index(patient_id);
                printf("%i\n", position_index);
                printf("You are position %i in the queue\n",position);
                break;
                case('q'):
                remove_patient(patient_id);
                print();
                break;
                case('d'):
                i = room;
                if(doctor_room[i] == 1 || doctor_room[i] == 2)
                    {
                        doctor_available = doctor_available + 1;
                    }
                printf("There are %i doctors available.\n", doctor_available);
                break;
                // the h command
                case('h'):
                printf("The 'i' command is for checking in\n");
                printf("The 'p' command is for checking your position in the queue\n");
                printf("The 'q' command is for checking out if you don't want to see a doctor\n");
                printf("The 'd' command is for checking how many doctors are available, and which room they are at\n");
                break;
            }
        }
            // if user is administrator
        if (service_choice == 2)
            {
                //check for the correct 4 digits password
                printf("Please enter your password\n");
                printf(">>>");
                scanf("%i", &password);
                // correct password
                if (password == 1234)
                {
                        printf("Please enter your command and room\n");
                        printf(">>>");
                        scanf(" %c %i", &service_command, &room);
                        if(doctor_room > 0 && room <=10)
                        {
                            switch (service_command)
                            {
                                case('o'):
                                printf("Please enter patient id:\n");
                                printf(">>>");
                                scanf(" %i", &patient_id);
                                if(IsEmpty())
                                {
                                    printf("There is no patient in the surgery.\n");
                                    if(patient_id == doctor_room[i])
                                    {
                                        doctor_room[i] = 2;
                                        printf("Patient check out successful\n");
                                    }
                                    else
                                    {
                                        printf("Are you sure this patient in your room?\n");
                                    }
                                }
                                break;
                                case('r'):
                                if(IsEmpty())
                                {
                                    printf("There is no patient here yet.\n");
                                    doctor_room[i] = 1;
                                }
                                else
                                {
                                    printf("Patient %i, please proceed to room %i.\n", patient_id, room = i + 1);
                                    patient_id = dequeue();
                                    doctor_room[i] = patient_id;
                                    for(i = 0; i<= max_room - 1; i++)
                                    {
                                        printf(" %i", doctor_room[i]);
                                    }
                                }
                                break;
                                case('a'):
                                if(patient_id == doctor_room[i])
                                {
                                    printf("Is the patient still inside the room? Check them out before.\n");
                                }
                                else
                                {
                                    doctor_room[i] = 0;
                                }
                                break;
                                case('w'):
                                print();
                                break;
                                case('x'):
                                service_stop = 1; // quits the program
                                printf("You have quit the service.\n");
                                break;
                            }
                        }
                    else
                    {
                        printf("Invalid room input. Please enter room 1 - 10.\n");
                    }

                    }
                }
            }
}
