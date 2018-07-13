// biến patient index
int patient_index(int id_number)
{
    int p_index = -1, i;
    if (IsEmpty())
    {
        return index;
    }
    for(i = 0; i<=max_patient - 1; i++)
    {
        if (patient_queue[i] == id_number)
        {
            index = i;
            if (first <=last)
            {
                if(index >=first && index <= last)
                {
                    return p_index;                    
                }
            }
            else if (first > last)
            {
                if (index >= first && index <=max - 1)
                {
                    return p_index;                    
                }
                else if (index >= 0 && index <= last)
                {
                    return p_index;                    
                }
            }
        }
    }
    return index; 
}

// biến patient position
int patient_position(int id_number)
{
    int p_position = -1, p_index;
    p_index = patient_index(id_number);
    if (index == -1)
    {
        return p_position = -1;
    }
    if (p_index >= first)
    {
        p_position = index - first + 1;
    }
    else
    {
        p_position = max_patient - first + index + 1;
    }
    return p_position;    
}

// biến remove
void remove_patient(int id_number)
{
    int p_index, i;
    if (IsEmpty())
    {
        printf("The queue is empty\n");
    }
    p_index = patient_index(id_number);// get the index of the remove id    
    else if(p_index == -1)
    {
        printf("You are not in the queue.\n");   
    }
    // if the queue is not empty
   else
   {
        // if index of id is smaller than index of last
        if(p_index < first)
        {
            for(i = p_index; i<=last-1; i++)
            {
                patient_queue[i] = patient_queue[i+1];
            }
            if(last == 0)
            last = max_patient - 1;
            else
            last = last - 1;
        }
       else
       {
            // if the queue wraps around
            if(first > last)
            {
                for (i = id_index; i < max_patient - 1; i++)
                {
                    {
                        patient_queue[i] = patient_queue[i+1];
                    }
                    last = last - 1
                }
                for (i = 0; i <= last - 1; i++)
                {
                      patient_queue[i] = patient_queue[i+1];
                }
                if(last == 0)
                last = max_patient - 1;
                else
                last = last - 1;            
            }
            // if the queue doesn't wrap around
            else
            {
                for(i = p_index; i <= last - 1; i++)
                {
                    patient_queue[i] = patient_queue[i+1];
                }
                if(last == first)
                first == last == -1;
                else
                last = last - 1;             
            }
        }
       }
}

