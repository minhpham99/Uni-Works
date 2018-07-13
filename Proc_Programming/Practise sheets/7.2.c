#include<stdio.h>
#include<string.h>

struct student
{
  char name[20];
  struct student *next;
};
struct student *list_student(const char student_name[20], struct student *next)
{
  student *new_student = (student*)malloc(sizeof(5));
  new_student-> student_name = student_name;
  new_student -> next = next;
  return new_student;
}
struct student *add_student(struct student *head; const char student_name[20])
{
    struct student *new_student = malloc(sizeof(struct student));
    // student_name will be copied to newStudent
    //new_student have access to name in struct student
    strcpy(new_student->name, student_name);
}
struct student *find_student(struct student *head, const char student_name[20])
{
  struct student *name_search = malloc(sizeof(struct student));
  // name_search will be compare with student_name
  // name_search have access to name in struct student
  strcmp(name_search->name, student_name);
  if(strcmp(name_search->name, student_name) !=0) return student_name;
  else return NULL;
}
struct student *delete_student(struct student *alumnus, struct student *head)
{
  struct student *prev = head;
  // find the previous student
  while(prev->next !=NULL && prev->next != alumnus)
    prev = prev ->next;
  //check if the student is in the list
  if(prev ->next == NULL)
  {
    printf("Student is not an alumnus\n");
    return;
  }
  // else, remove the student from the list
  prev->next = prev->next->next;
  // free the student
  free(alumnus);

  return;
}
void print_reverse(struct student *head)
{
  struct student *prev_student = NULL;
  struct student *current_student = *head;
  struct student *next;
  while(current !=NULL)
  {
      next = current_student -> next;
      current_student -> next = prev_student;
      prev_student = current_student;
      current_student = next;
  }
  *head = prev_student;
}
