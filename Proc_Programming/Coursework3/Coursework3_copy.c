#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<ctype.h>

const int max_x=61, max_y=31, max_stars=max_x*max_y, max_pairs=max_stars/2;
char galaxy[max_y][max_x]; // frame buffer
int star_number, pair_number;
/********************************************** STRUCTS *******************************************************/
struct galaxy_size
{
    int star_no;
    int pair_no;
};
// stores all the details about a star
struct star_data
{
    int id;
    double x;
    double y;
    char name[25];
};
// array to store all the stars
struct star_data stars[max_stars];
// store all the star pairs
struct pair_data
{
    int id;
    int star1_id;
    char star1_name[25];
    int star2_id;
    char star2_name[25];
    double star_distance;
};
// array to store all the pairs
struct pair_data star_pairs[max_pairs];

// remove leading space of string
char *ltrim (char *trim_s) 
{
    int i = 0, n = strlen(trim_s) ;
    while (isspace((unsigned char) trim_s[i]))
        i++ ;

    //if (i != 0) strcpy (trim_s, trim_s + i);
    for (int j = 0 ; i <= n ; i++, j++)
            trim_s[j] = trim_s[i];

    return trim_s;
}
// remove trailing space of string
char *rtrim (char *trim_s) 
{
    int i = strlen (trim_s) - 1 ; // strlen(trim_s) -1 = last index of the string
    while (isspace((unsigned char) trim_s[i]) && i >= 0) // check space in string
        i-- ; // move to previous index, til isspace() is true

    trim_s[i+1] = '\0'; // terminate new string by replace i+1 with \0 to end the string at i;

    return trim_s;
}
/********************************************** VOID FUNCTIONS *******************************************************/
// clear the frame buffer by filling it with whitespace
void clear()
{
    for(int i = 0; i<=max_y -1; i++) // scan row (y)
    {
        for(int j = 0; j<=max_x-1; j++) //scan column (x)
        {
            galaxy[i][j] = ' ';
        }
    }
}
// reset the universe
void reset()
{
    int i;
    for (i = 0; i <= max_stars - 1; i++)
    {
        stars[i].id = -1;
        stars[i].x = -1;
        stars[i].y = -1;
        strcpy(stars[i].name, " ");
    }
    for (i = 0; i <= max_pairs - 1; i++)
    {
        star_pairs[i].id = -1;
        star_pairs[i].star1_id = -1;
        strcpy(star_pairs[i].star1_name, " ");
        star_pairs[i].star2_id = -1;
        strcpy(star_pairs[i].star2_name, " ");
        star_pairs[i].star_distance = -1;        
    }
    star_number = 0;
    pair_number = 0;
}
// stores the character to the frame buffer
void plot(int x, int y, char c)
{
    galaxy[y][x] = c;
}
// copy the string write_s to the frame buffer 
void write_at(int x, int y, char *write_s)
{
    int i;
    for(i = 0; i <= strlen(write_s); i++)
    {
        if (x+i <= max_x - 1) plot(x + i, y, write_s[i]); // stop plotting if x+i is out of range of frame buffer
        else return;
    }
}
// clears the terminal and print the frame buffer
void refresh()
{
    int i, j, x, y;
    char star_name[25];
    // initialise the frame buffer to whitespace
    clear();
    // fill the frame buffer
    for (i = 0; i <= star_number - 1; i++)
    {
        x = (int) stars[i].x;
        y = (int) stars[i].y;
        strcpy(star_name, stars[i].name);
        if (strcmp(star_name, " ") == 0) plot(x, y, '.');
        else plot(x, y, '*');
    }
    // clears the terminal
    system("clear");   
    // print the entire frame buffer
    for(i = 0; i <= max_y - 1; i++) // check the row y
    {
        for(j = 0; j <= max_x - 1; j++) // check the column x
        {
            printf("%c", galaxy[i][j]);
        }
        printf("\n");
    }
}
//find star exist at x, y
int find_star(int star_x, int star_y)
{
    int i, star_id = -1;
    for(i = 0; i <=max_stars-1; i++)
    {
        if(stars[i].x == star_x && stars[i].y == star_y) return star_id = stars[i].id;
    }
    return star_id;
}
// generates random stars
void bang(int num)
{
    int i, x, y, star_found = -1;
    for(i = 0; i<=num-1; i++)
    {
        do    
        {
            x = rand()%max_x;
            y = rand()%max_y;
            star_found = find_star(x, y);
        } while (star_found != -1);
        
        stars[i].id = i;
        stars[i].x = x;
        stars[i].y = y; 
    }  
}
// print the stars
void list_stars()
{
    int i;
    char name[25];
    if (star_number == 0)
    {
        printf("The universe have not been created!");
        return;
    }

    for (i = 0; i <= star_number-1; i++)
    {
        printf("Star:%.2i\n", stars[i].id);
        if(strcmp(stars[i].name, " ") !=0) printf("Name: %s\n", stars[i].name); // if the star has been named this will be printed
        printf("Coordinates:(%.3lf, %.3lf)\n", stars[i].x, stars[i].y);
        printf("\n");
    }
}
//print pairs of stars
void list_pair()
{
    int i;
    if (pair_number == 0)
    {
        printf("No pair has been created yet!\n");
        return;
    }
    for (i = 0; i <= pair_number - 1; i++)
    {
        printf("Pair:%i\n", star_pairs[i].id);
        printf("Star 1 id:%i\n",star_pairs[i].star1_id);
        printf("Star 1 name: %s\n", star_pairs[i].star1_name);
        printf("Coordinates:%lf, %lf\n", stars[star_pairs[i].star1_id].x, stars[star_pairs[i].star1_id].y);
        printf("Star 2 id:%i\n",star_pairs[i].star2_id);
        printf("Star 2 name: %s\n", star_pairs[i].star2_name);
        printf("Coordinates:%lf, %lf\n", stars[star_pairs[i].star2_id].x, stars[star_pairs[i].star2_id].y);
        printf("Distance between the stars:%lf\n", star_pairs[i].star_distance);
        printf("\n");
    }   
}
//find and create closest stars pair
void name_star()
{
    int i,j, star_id1 = -1, star_id2 = -1, star_index1 = -1, star_index2 = -1;
    char input_str[25]="\0", star_name1[25]="\0", star_name2[25] = "\0",name_command;
    double min_distance = sqrt(pow(max_x,2)+pow(max_y,2)), distance_x, distance_y, star_distance;
    
    if (star_number == 0)
    {
        printf("The universe have not been created!");
        return;
    }
    // find closest pair
    for (i = 0; i<=star_number - 2; i++)
    {
        // if the star already got a name
        if (strcmp(stars[i].name, " ") != 0) continue;
        for(j = i + 1; j<=star_number - 1; j++)
        {
            if (strcmp(stars[j].name, " ") !=0) continue;
            // calculate distances
            distance_x = fabs(stars[i].x - stars[j].x);
            distance_y = fabs(stars[i].y - stars[j].y);
            star_distance = sqrt(pow(distance_x,2)+pow(distance_y,2));
            
            if (star_distance < min_distance) 
            {
                min_distance = star_distance;
                star_id1 = stars[i].id;
                star_index1 = i;
                star_id2 = stars[j].id;
                star_index2 = j;
            }
        }
    }
    // if there is no pair left
    if ( star_id1 == -1 && star_id2 == -1 )
    {
        printf("Sorry, no pairs were found.\nWish you a better luck in the next universe.\n");
        return;
    }
    printf("The closest pair of stars are no. %i and %i\n", star_id1, star_id2);
    printf("They are %lf light years apart\n", min_distance);
    
    printf("Would you like to name this pair (y/n)? "); // ask user whether to name pair
    scanf("%c", &name_command);
    while(getchar() != '\n'); // clear unwanted characters remain in stdin

    // if user decide not to name
    if (name_command != 'y')
    {
        printf("You have chosen not to name this pair\n");
        return;
    }  
    // input name of user  
    do
    {   
        printf("Enter your full name: ");
        fgets(input_str, 26, stdin);
        if (input_str[strlen(input_str)-1] != '\n') while(getchar() != '\n'); //Clear unwanted characters remain in stdin. after fgets
        if (input_str[strlen(input_str)-1] == '\n') input_str[strlen(input_str)-1] ='\0'; //remove \n out of input

        strcpy(star_name1, rtrim(ltrim(input_str)));      
    } while (star_name1[0] == '\0'); // ensure the user enters a string  
    // input name of user's spouse
    do
    {   
        printf("Enter your spouse's full name: ");
        fgets(input_str, 26, stdin);
        if (input_str[strlen(input_str)-1] != '\n') while(getchar() != '\n'); //Clear unwanted characters remain in stdin. after fgets
        if (input_str[strlen(input_str)-1] == '\n') input_str[strlen(input_str)-1] ='\0'; //remove \n out of input

        strcpy(star_name2, rtrim(ltrim(input_str)));      
    } while (star_name2[0] == '\0'); 
    // assigned star pairs 
    pair_number = pair_number + 1;
    star_pairs[pair_number - 1].id = pair_number - 1;
    star_pairs[pair_number - 1].star1_id = star_id1;
    strcpy(star_pairs[pair_number - 1].star1_name, star_name1);
    star_pairs[pair_number - 1].star2_id = star_id2;
    strcpy(star_pairs[pair_number - 1].star2_name, star_name2);
    star_pairs[pair_number - 1].star_distance = min_distance;
    // assigned name to stars
    strcpy(stars[star_index1].name, star_name1);
    strcpy(stars[star_index2].name, star_name2); 

    printf("Congratulation a pair of stars has been name after you and your spouse\n");
}
void show_name()
{
    int i, j, x, y, star_x1, star_y1, star_x2, star_y2, write_x, write_y, star_id;
    char input_str[25], star_name[25];
    // input user's name
    do
    {   
        printf("Enter your full name: ");
        fgets(input_str, 26, stdin);
        if (input_str[strlen(input_str)-1] != '\n') while(getchar() != '\n'); //Clear unwanted characters remain in stdin. after fgets
        if (input_str[strlen(input_str)-1] == '\n') input_str[strlen(input_str)-1] ='\0'; //remove \n out of input

        strcpy(star_name, rtrim(ltrim(input_str)));      
    } while (star_name[0] == '\0'); // ensure the user enters a string 

    // check if name is given or in the star_pair array
    for (i = 0; i <= pair_number -1; i++)
    {
        if (strcmp(star_name, star_pairs[i].star1_name) != 0 && strcmp(star_name, star_pairs[i].star2_name) != 0)
        {
            printf("Star name is not found.\n");
            return;
        } 
    }
    star_id = stars[i].id;
    x = stars[i].x;
    y = stars[i].y;
    printf("%i\n%i\n%i\n",star_id,x,y);
   
    for (i = 0; i<=max_y - 1; i++)
    {

    } 
    // neu tim duoc pair 
        // lay thong tin cua ngoi sao
        // xac dinh toa do write_s()
            // toa do y la dong tiep theo cua y lon hon trong 2 chi so y
                // write_y = (star_y1 <= star_y2) ? star_y2 +1: star_y1 +1; (lay dong tiep theo cua y lon hon (y+1)) 
                // write_y > max_y -1 => truong hop y qua mang max_y -1,lay dong truoc y nho hon(y nho -1)  => write_y = (star_y1 <= star_y2) ?: star_y1 - 1: star_y2 -1; 
            // toa do x 
                // tim strlen()
                // star_x tuong duong voi star_y(ca 2 dong)
                // write_x = star_x - strlen()/2 + 1 => de cho string vao giua thi chia strlen()/2 
                // kiem tra vi tri write_x + strlen() -1 > max_x - 1 => write_x = max_x - 1 - strlen() + 1 (vi tri cuoi cung la max_x - 1 tru di strlen(), khi co kha nang vuot qua mang) 
                // kiem tra write_x < 0 => dat write_x = 0 , viet tu 0 tro di (kiem tra cuoi cung de phu hop ca 2 truong hop tren, chi can kiem tra 1 lan)
    
        // chay clear()
        // fill buffer giong refresh
        // chay write_s()
        // clear man hinh
/*     clear();
    // fill the frame buffer
    for (i = 0; i <= star_number - 1; i++)
    {
        x = write_x;
        y = write_y;
        strcpy(star_name, stars[i].name);
        if (strcmp(star_name, " ") == 0) plot(x, y, '.');
        else plot(x, y, '*');
    }
    write_at(x,y, star_name);
    // clears the terminal
    system("clear");   
    // print the entire frame buffer
    for(i = 0; i <= max_y - 1; i++) // check the row y
    {
        for(j = 0; j <= max_x - 1; j++) // check the column x
        {
            printf("%c", galaxy[i][j]);
        }
        printf("\n");
    }   */ 
}
void save_galaxy()
{
    FILE *ptr_galaxy;
    struct galaxy_size g_size;
    ptr_galaxy = fopen("universe.bin", "wb");
    
    if(!ptr_galaxy)
    {
        printf("Unable to save file!\n");
        return;
    }
    // assign star number
    g_size.star_no = star_number;
    // assign pair number    
    g_size.pair_no = pair_number;
    // save the star and pair number
    fwrite(&g_size, sizeof(g_size), 1, ptr_galaxy);
    // save the struct of stars and star_pairs
    if (fwrite(&stars, sizeof(struct star_data), star_number, ptr_galaxy) != star_number)
    {
        printf("Error when saving the universe.\n");
        return;
    }

    if (fwrite(&star_pairs, sizeof(struct pair_data), pair_number, ptr_galaxy) != pair_number)
    {
        printf("Error when saving the universe.\n");
        return;
    }
 
    // close the file
    fclose(ptr_galaxy);
    printf("Thanks, you have saved the universe!\n");
}
void load_galaxy()
{
    FILE *ptr_galaxy;
    struct galaxy_size g_size;

    ptr_galaxy = fopen("universe.bin", "rb");
    // if user hasn't save yet
    if (!ptr_galaxy)
    {
        printf("Unable to open file! Have you save your universe?\n");
        return;
    }

    reset();
    // read star and pair number
    fread(&g_size, sizeof(g_size), 1, ptr_galaxy);

    // read the stars array from file, check if fread read the block number = g_size.star_no
    if (fread(&stars, sizeof(struct star_data), g_size.star_no, ptr_galaxy) < g_size.star_no)
    {
        printf("Error when load the universe from saved file!\n");
        return;
    }
    star_number = g_size.star_no;

    // read the star_pairs array from file, check if fread returns the block number = g_size.pair_no
    if (fread(&star_pairs, sizeof(struct pair_data), g_size.pair_no, ptr_galaxy) < g_size.pair_no)
    {
        printf("Error when load the universe from saved file!\n");
        return;
    }
    pair_number = g_size.pair_no;

    // close the file
    fclose(ptr_galaxy);
    printf("Congratulations, your universe has been restored.\n");
}
/********************************************** MAIN FUNCTION *******************************************************/
int main()
{
    time_t t;
    char game_command[7], g_command[15];
    int game_stop, command_id;
    
    game_stop = 0;
    srand((unsigned) time(&t));
    
    printf("Welcome to the Big Bang Simulation.\n");
    while (game_stop == 0)
    {
        command_id = 0;
        //printf("Enter your command, with number of stars if applicable\n");
        printf(">>>");
        //scanf( " %s", game_command);
        fgets(g_command, 16, stdin);
        if (g_command[strlen(g_command)-1] != '\n') while(getchar() != '\n'); //Clear unwanted characters remain in stdin. after fgets
        if (g_command[strlen(g_command)-1] == '\n') g_command[strlen(g_command)-1] ='\0'; //remove \n out of input

        sscanf(g_command, "%s %d", game_command, &command_id);

        // the CLI
        // the bang command
        if (strcmp(game_command, "bang") == 0)
        {    
            if (command_id > 0 && command_id <= max_stars)
            {
                reset();
                star_number = command_id;
                bang(star_number);        
             }
             else printf("Invalid star number.\n");
        }
        // the list command
        else if (strcmp(game_command, "list") == 0)
        {
            list_stars();
        }
        // the name command
         else if (strcmp(game_command, "name") == 0)
        {
            name_star();
        }
        // the pairs command
         else if (strcmp(game_command, "pair") == 0)
        {
            list_pair();
        }
        // the draw command
         else if (strcmp(game_command, "draw") == 0)
        {
            refresh();
        }
        // the show command
         else if (strcmp(game_command, "show") == 0)
        {
            show_name();
        }
        // the save command
         else if (strcmp(game_command, "save") == 0)
        {
            save_galaxy();
        }
        // the load command
          else if (strcmp(game_command, "load") == 0)
        {
            load_galaxy();
        }
        // the quit command
          else if (strcmp(game_command, "quit") == 0)
        {
            game_stop = 1;
            printf("You have quit the program.\n");
        }
        else
        {
            printf("Invalid command.\n");
        }
    }
    return 0;
}