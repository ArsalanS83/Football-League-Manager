/*  Football League Program.c
 *  Manages a Football League of 10 Teams
 *  Created by Arsalan Sadeghpour on 24/01/2013.
 */

#define MAXTEAMS 10
#define MAXGAMES 18
#define MAXLENGTH 15 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct team                   /* Team Structure To Hold Team Data */
{
	char name [MAXLENGTH];
	int pld;
	int w;
	int d;
	int l;
	int pts;
};

 
struct game                    /* Game Structure To Hold Game Data*/
{
	char hometeam [MAXLENGTH];
	char awayteam [MAXLENGTH];
	int homegoals;
	int awaygoals;
};

void createleague(struct team leagueteams[], struct game fixtures[]);
void displayleague(struct team leagueteams[]);
void addmatch(struct team leagueteams[], struct game fixtures[],int gameno);        /* Function Prototypes */
void displayhistory(struct team leagueteams[]);

int main (void)
{
	struct team leagueteams[MAXTEAMS];
	struct game fixtures[MAXGAMES];
	int gameno=0;
    int menuchoice;
    
    printf("**********************************\n");
	printf("Welcome To The Premier League\n");
	printf("**********************************\n");
    
    do
    {
        printf("\n*****************************\n");
        printf("1. Create League");
        printf("\n2. Display League");
        printf("\n3. Add Match Scores");
        printf("\n4. Display Team Game History");                    /* Program Menu */
        printf("\n5. Exit\n");
        printf("*****************************\n");
        printf("\nEnter Your Choice: ");
        scanf("%d",&menuchoice);
        fflush(stdin);
        
        switch (menuchoice)
        {
            case 1:
                createleague(leagueteams, fixtures);
                break;
            case 2:
                displayleague(leagueteams);
                break;
            case 3:
                addmatch(leagueteams,fixtures,gameno);
                break;
            case 4:
                displayhistory(leagueteams);
                break;
            case 5:
                exit(0);
        }
    } while (menuchoice !=5);
}


void createleague(struct team leagueteams[], struct game fixtures[])   /* Initialising The League */
{
	int t;
	int g;
	printf("\n\nEnter 10 Teams To Create The League\n");
	
    for (t=0;t<MAXTEAMS;t++)
	{
        printf("\n\nEnter Team: ");
		scanf("%s",&leagueteams[t].name);
		fflush(stdin);
		leagueteams[t].pld = 0;
		leagueteams[t].w=0;
		leagueteams[t].d=0;
		leagueteams[t].l=0;
		leagueteams[t].pts=0;
	}
	
	for (g=0;g<MAXGAMES;g++)
	{
		fixtures[g].homegoals = 0;
		fixtures[g].awaygoals = 0;
	}
}


void displayleague(struct team leagueteams[])       /*Displaying The League Table*/
{
    
	int d;
	printf("\n\nPremier League Table\n");
	printf("\n----------------------------------------\n");
	printf("\t Name     P   W   D   L   Pts\n");
	printf("------------------------------------------\n");
	
	for (d=0;d<MAXTEAMS;d++)
	{
		printf("%15s %3d %3d %3d %3d %3d\n", leagueteams[d].name,leagueteams[d].pld, leagueteams[d].w, leagueteams[d].d,leagueteams[d].l,
               leagueteams[d].pts);
	}
	
    
}




void addmatch(struct team leagueteams[], struct game fixtures[],int gameno)  /* Adding Matches & Updating The League Table */
{
	int h;
	int a;
	int validteam=0;
	
	while(validteam==0)
	{
        
		printf("\nEnter Home Team: ");
		gets(fixtures[gameno].hometeam);
		
		for (h=0;h<MAXTEAMS;h++)
		{
            
            if (strcmp(fixtures[gameno].hometeam, leagueteams[h].name)==0)
            {
                
                validteam=1;
                break;
            }
		}
		
		if (validteam==0)
		{
            printf("\nError Home Team does not exist/n");
		}
	}
	
	validteam=0;
    while(validteam==0)
	{
		printf("\nEnter Away Team: ");
		gets(fixtures[gameno].awayteam);
		
		
		for(a=0;a<MAXTEAMS;a++)
		{
			if(strcmp(fixtures[gameno].awayteam, leagueteams[a].name)==0)
			{
				validteam=1;
				break;
			}
		}
		
		if(validteam==0)
		{
			printf("\nError Away Team does not exist\n");
		}
	}
	
    printf("\nEnter Home Score: ");
    scanf("%d", &fixtures[gameno].homegoals);
    fflush(stdin);
    
    printf("\nEnter Away Score: ");
    scanf("%d", &fixtures[gameno].awaygoals);
    fflush(stdin);
    
	
	if (fixtures[gameno].homegoals == fixtures[gameno].awaygoals)
	{
		leagueteams[h].pts++;
		leagueteams[a].pts++;
		leagueteams[h].d++;
		leagueteams[a].d++;
	}
	else if(fixtures[gameno].homegoals > fixtures[gameno].awaygoals)
	{
		leagueteams[h].pts+= 2;
		leagueteams[a].pts-= 1;
		leagueteams[h].w+=1;
		leagueteams[h].l+=1;
	}
	else if(fixtures[gameno].awaygoals > fixtures[gameno].homegoals)
	{
		leagueteams[h].pts-= 1;
		leagueteams[a].pts+= 3;
		leagueteams[a].w+=1;
		leagueteams[h].l+=1;
	}
	
	
	leagueteams[h].pld++;
	leagueteams[a].pld++;
}

void displayhistory(struct team leagueteams[])       /* Displaying Team Game History */
{
        char teamname[MAXLENGTH];
		int i;
		
		
		printf("\nEnter Team To See History: ");
        scanf("%s",&teamname);
		
		
		for (i=0;i<MAXTEAMS;i++)
		{
			if(strcmp(teamname,leagueteams[i].name) ==0)
			{
				break;
			}
		}
        printf("\nTeam: %s\n",leagueteams[i].name);
        printf("\nGames Played: %d\n\n",leagueteams[i].pld);
        printf("Games Won: %d\n\n",leagueteams[i].w);
        printf("Games Drawn: %d\n\n",leagueteams[i].d);
        printf("Games Lost: %d\n\n",leagueteams[i].l);
        printf("Points: %d\n",leagueteams[i].pts);	  
}

