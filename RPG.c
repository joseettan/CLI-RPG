#include<stdio.h>
#include<conio.h>
#include<strings.h>

//Functions I am going to define that I don't know of but there is probably a better way to do this
char firstName();
char bettergets(); //clears input buffer and takes in input, basically, ignores \n from previous gets.

//Actual Functions required in the game
int choose();
void equip();
void map(); void mapft();
void changeto();
void commgen();


/*GLOBAL VARIABLES*/
//MAP DISCOVERYS
int faze,optics, fnatics,nvs;  // These variables indicate if the place has been discovered or not
int ftallow;  //Tells if fast travel is allowed or not like during combat
int currentloc;

//COMMAND LINE
//Bettergets
int btrgts=0;

void main()
{
    //Title screen
    printf("*********************************************************************************************************\n");
    printf("*\t\t\t\t\tTHE DUNGEONS CLI RPG \t\t\t\t\t\t*\n");
    printf("*********************************************************************************************************\n");

    //Character Creation
    printf("Welcome Adventurer,\n Ah, you are awake \n You have travelled far into the Forbidden Jungle of Azekaphar.");
    printf("These are dangerous places, and dangerous times \n");
    printf("Tell me, what is your name traveller? \n YOU:\t");

    int choice;
    int age;
    char namePlayer[30], fname[30];

    scanf("%[^\n]s",namePlayer);
    firstName(namePlayer,fname);
    printf("\n %s, Why have you come to this cursed lands?\n",fname);
    printf("[1. I don't know \t 2. Why do you care old man \t 3. I lost my way over here] \n");
    printf("== \tWhen '[ ]' is displayed, a choice can be made. Simply enter the number corresponding to the choice. \t== \n");

    choose(&choice);
    switch(choice){
        case 1:printf("You must've lost your memories under the Tree of Thousand Blossoms\n");break;
        case 2:printf("How rude of you to say that to the man that just saved your life?\n");break;
        case 3:printf("Child, nobody is lost. There are no mistakes \n.");break;
        default: printf("You picked the wrong house fool \n \n"); break;
    }
    printf("However, I found you lying there under the Tree of Thousand Blossoms. You seem to be quite lost \n");
    printf("Tell me, what's your age? \n YOU:\t");
    scanf("%d",&age);
    printf("(laughing) You surely don't look %d. You seem to have really lost your memories. \n",age);
    printf("But that could only happen to the Chosen One. Could it be? But the legends?! \n ");
    printf("[1. Let's get outta here Mastuhchief \t 2. I am the Chosen One \t 3. What are you talking about]\n");
    choose(&choice);
    switch(choice){
        case 1:printf("Ah.. I see you are a man of culture as well \n");break;
        case 2:printf("But for someone like you to be the One! How can it be? \n");break;
        case 3: printf("The Chosen One, like in all other games and literature, will save us from the Great Villain \n");break;
        default: printf("You picked the wrong house fool \n \n"); break;
    }

    printf("Your journey begins traveller, you've chosen the path. \n Oh how rude of me to not introduce myself. I'm Greg Kelsoe. \n I am the chief of this tribe.");
    printf("I think that's all you need to know now. \n You seem to be healed, head on out Chosen One \n");
    printf("[1. Head Out \t 2. What does it mean to be the Chosen One? \t 3. This is BS, I'm getting outta here!] \n");
    choose(&choice);
     switch(choice){
        case 1:printf("(Heads out) \n");break;
        case 2:printf("Greg:\tOh why, it means everything. \n The ability to change whatever he wanted, to remake the World as you see fit. \n To dodge bullets, oh wait, bullets aren't a thing yet. Oh well.  \n (heads out)\n");break;
        case 3: printf("Greg:\tYou aren't going anywhere. To have crossed the Great Lake once is just sheer luck. Luck won't help you next time \n (heads out)\n");break;
        default: printf("You picked the wrong house fool.\n"); break;
    }
        //MAIN GAME STARTS

        char command[20];
        int i=0;

    printf("********************************\n");
    printf("* DISCOVERED PHAZE CLAN HOLDOUT *\n");
    printf("********************************\n");
    faze=0;
    printf("Danks:\t Greg thinks you're the Chosen One. BS\n");
    printf("[1. What do you want big guy? \t 2. I think the same!");
    choose(&choice);
    switch(choice){
        case 1: printf("Danks:\tDon't act tough, we all know who you are.\n");break;
        case 2: printf("Danks:\tAtleast someone knows his stuff around. \n");break;
        default: printf("Danks:\tYou picked the wrong house fool.\n");break;
    }
    printf("Danks:\t Greg wants me to show you around. \nDanks:\tHere, take this map. It'll help you in your journey. \n");
    printf("*Map Added* \n");
    printf("==\t To equip map, type switch and hit return/enter. Then type switchto map. \t==\n");
    currentloc=1;
    commgen();




}
int choose(int a)
{
    printf("\n YOU:\t");
    scanf("%d",a);
    return a;
}

void commgen()
{
    int i;
    char command[20];
    i=0;
    while(i==0){
    printf("COM:\t \t");
        bettergets(command);
        if(strcmp(command,"switch")==0){changeto(); i++;break;}
        if(strcmp(command,"ft")==0){mapft(); i++; break; }

        if(i==0){printf("Command not found \n"); continue;}
        }

}


void changeto()
{
        int i=0;
     char command[20];
     while(i==0){
     printf("SWITCH: \t");
        bettergets(command);

        if(strcmp(command,"switchto World")==0) {/*world()*/printf("World is loaded \n"); i++;}
        if(strcmp(command,"switchto map")==0) { map();i++;}
        if(strcmp(command,"switchto weapons")==0) {/*weapons()*/printf("Weapons is loaded\n");; i++;}
        if(strcmp(command,"switchto items")==0) { /*items()*/printf("Items is loaded\n");; i++;}
        if(strcasecmp(command, "COM")==0) commgen();
        if(i==0) {printf("Invalid command\n"); continue;}

     }
}


void map(){

    printf("\n\n.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:\n");
    printf("||\t\t\tMAP\t\t\t\t||\n");
    printf(".:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:\n\n");
    printf("\n ");

        puts("         --------------------------\n"
"   .----/	|	 	   \\---.\n"
"   |		|			\\\n"
" .-*	PHAZE	|			 *-.----.\n"
" |		!	FANATICS          /	\\.\n"
"  *    _......-**!			 /	  `!\n"
"   *../		  `*-__/\\_     __......./        ../\n"
"    *		      !   \\__/*			\\\n"
"  .*		      !			    ..~-*\n"
"  |		       `\\	eNVieduS    !\n"
"   *	 HOPTICS	/		    |\n"
"     *		       /	    .~``*-.*'\n"
"	*	      /		_.-`\n"
"	  *-__.____.-*\\._.----~  \n");
    printf("\n");


    printf("*Phaze Clan Holdout \t [%c] [%c]\n*Team Hoptics Stronghold [%c] [%c] \n*Fanatics Stronghold \t [%c] [%c] \n*eNVieduS Holds \t [%c] [%c]  \n",(faze==1)?'O':'-',(currentloc==1)?'@':'-',(optics==1)?'O':'X',(currentloc==2)?'@':'-',(fnatics==1)?'O':'X',(currentloc==3)?'@':'-',(nvs==1)?'O':'X',(currentloc==4)?'@':'-');
    printf("== \t[X]: Not Travellable\t [O]: Travellable\t [@]: Current Location\n");
    printf("==\t To exit map, type switch and hit return/enter. then type switchto World \t==\n");
    printf("==\t To fast travel, type ft and hit return/enter. then enter ft <holdout> \t==\n");
    commgen();


}

void mapft(){
     int i=0;
     char command[20];
     while(i==0){
     printf("FAST TRAVEL: \t");
        bettergets(command);

        if(strcmp(command,"ft phaze clan holdout")==0 && faze==1 && ftallow==1 && currentloc!=1) {printf("Travelling to Phaze Clan Holdout \n"); i++;}
            else {printf("Fast travel not allowed or this place has not yet been discovered or you are now at this place.\n"); continue;}
        if(strcmp(command,"team hoptics stronghold")==0 && optics==1 && ftallow==1 && currentloc!=2) { printf("Travelling to Team Hoptics Stronghold\n");i++;}
             else {printf("Fast travel not allowed or this place has not yet been discovered or you are now at this place.\n"); continue;}
        if(strcmp(command,"fanatics stronghold")==0 && fnatics==1 && ftallow==1 && currentloc!=3) {printf("Travelling to Fanatics Stronghold");; i++;}
             else {printf("Fast travel not allowed or this place has not yet been discovered or you are now at this place.\n"); continue;}
        if(strcmp(command,"enviedus holds")==0 && nvs==1 &&  ftallow==1 && currentloc!=4) { printf("Travelling to eNVieduS Holds");; i++;}
             else {printf("Fast travel not allowed or this place has not yet been discovered or you are now at this place.\n"); continue;}
        if(i==0) {printf("Invalid command\n"); continue;}



     }
}






/*FUNCTIONS I WROTE BECAUSE I DONT KNOW ANY PRE-DEFINED FUNCTIONS AND PROBABLY COULD BE DONE IN A BETTER WAY*/
char firstName(char a[30],char b[30]) //for extracting first name from full name entered first
{
    int i;
    char temp;
    for(i=0;i<=strlen(a);i++)
    {
        if(a[i]!=' ')
        {
            b[i]=a[i];
        }
        else { b[i]='\0'; break;}
    }
}


char bettergets(char a[30]) //A better gets function that flushes input buffer
{
    if(btrgts!=0)
        gets(a);
    else{
    char b;
    b=getchar();
    gets(a);
    }
    btrgts++;


}
