#include <stdio.h>     
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
int checkwall(int u1, int u2,int u3);
void placewall(int x00, int y00, int kt);
int think();
int checkmove(int y2, int x2);
int checkblock(int q1, int q2, int q3, int q4);
void showTable();
void movebot();
void botwall();
char **table;
char *apa,*ansr,*ansr2;

char alphaba[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
int N,trn,players,y5;
int pinf[10][10];
int pl[4][5];
char k[50];
int main(void)
{
	
	int choice,n,i,j,x,y,y3,done,w,x1,x11,postu,y21,x21,ext=0,mm,y4,opa;
 	char name1[100],str,y1,y11;
 	char name2[100];
 	char name3[100];
 	char name4[100];
 	ansr=(char *) malloc(4*sizeof(char));
 	ansr2=(char *) malloc(6*sizeof(char));
 	apa=(char *) malloc(4*sizeof(char));
 
 	do
 	{
 		printf("Press 1 for default map or 2 for custom map\n");
		scanf("%d",&choice);
	}while(choice!=1 && choice!=2);
	
    		
	if (choice==1)
	{
		N=10;  
	}
	else 
	{
		do
		{
			printf("Give row and columms:");
			scanf("%d", &N);
		}while(N<5);
	}
	
	do  
 	{
 		opa=0;
 		table = (char **) malloc(N*sizeof(char*));
 		if(table!=NULL)
 		{
 			opa++;	
		}
 	}while(opa==0);
    for(i=1; i<=N; i++)
    {
	 	do   
 	{
 		opa=0;
 		table[i] = (char *) malloc(N*sizeof(char));
 		if(table!=NULL)
 		{
 			opa++;	
		}
 	}while(opa==0);
	for(j=0; j<N; j++)
	{
	    table[i][j]='.';
	}
    }
    
	do{
		printf("Type players number(must be more than 1 and less than 5)\n");
		scanf("%d",&choice);
	}while(choice!=2 && choice!=4);
	
	if(choice==2)
	{
		printf("give name:");
		scanf("%s", &name1);
		printf("that player gonna be bot or not?1 for yes or 2 for no");
		scanf("%d",&n);
		table[N][N/2]='@';
		pl[0][1]=N; //x
		pl[0][0]=N/2;//y
		pl[0][2]=n;
		pl[0][3]=5;
		pl[0][4]=1;
		
		
		printf("give name:");
		scanf("%s", &name2);
		printf("that player gonna be bot or not?1 for yes or 2 for no");
		scanf("%d",&n);
		table[1][N/2]='#';
		pl[1][1]=1;
		pl[1][0]=N/2;
		pl[1][2]=n;
		pl[1][3]=5;
		pl[1][4]=2;
		
		players=2;
	}
	else
	{
		players=4;
		printf("give name:");
		scanf("%s", &name1);
		printf("that player gonna be bot or not?1 for yes or 2 for no");
		scanf("%d",&n);
		table[N][N/2]='@';
		pl[0][1]=N;//x
		pl[0][0]=N/2;//y
		pl[0][2]=n;
		pl[0][3]=5;
		pl[0][4]=1;
		
		printf("give name:");
		scanf("%s", &name2);
		printf("that player gonna be bot or not?1 for yes or 2 for no");
		scanf("%d",&n);
		table[N/2][N-1]='&';
		pl[1][1]=N/2;
		pl[1][0]=N-1;
		pl[1][2]=n;
		pl[1][3]=5;
		pl[1][4]=4;

		printf("give name:");
		scanf("%s", &name3);
		printf("that player gonna be bot or not?1 for yes or 2 for no");
		scanf("%d",&n);
		table[1][N/2]='#';
		pl[2][1]=1;
		pl[2][0]=N/2;
		pl[2][2]=n;
		pl[2][3]=5;
		pl[2][4]=2;
		
		printf("give name:");
		scanf("%s", &name4);
		printf("that player gonna be bot or not?1 for yes or 2 for no");
		scanf("%d",&n);
		table[N/2][0]='%';
		pl[3][1]=N/2;
		pl[3][0]=0;
		pl[3][2]=n;
		pl[3][3]=5;
		pl[3][4]=3;
	}

	do
	{
		printf("Press 2 for empty table, 1 for extra walls.");
		scanf("%d",&choice);
	}while(choice!=1 && choice!=2);
	printf("hi\n");
	if(choice==1)
	{
		w=((5*(N*N))/100);
		srand((unsigned) time(NULL));
		for(i=w; i>0; i--)
		{
			done=0;
	 	   do
	 	   {
	 	        x=rand() % N;
	  	        y=rand() % N;
	  	       	if(table[x][y]=='.')
	         	{
	         		table[x][y]='X';
	         		done=1;
				 }
			}while(done!=1);
		}
	}
	showTable();
	printf("\n");
	printf("give any key to start the game :)\n");
	scanf("%s", &str);
	printf("game begins\n");
	printf("-----------\n");
	do
	{
	for(trn=0; trn<players; trn++)
	{
	if(pl[trn][2]==1)
	{
	do
	{
		postu=1;		
		do
		{
			y5=0;
			printf("Press q to move, w to block.\n");
			printf("Type help for help.\n");
			printf("Type exit to exit the game.\n");
			scanf("%s", apa);
			y4=apa[0];
			for(i=0; i<=3; i++)
			{
				y5=apa[i]+y5;
			}
		}while(y4!=81 && y4!=87 && y4!=113 && y4!=119 && y5!=(72+69+76+80) && y5!=(69+88+73+84) && y5!=(104+101+108+112) && y5!=(101+120+105+116));
		if(apa[0]==113 || apa[0]==81)//q
		{
			do
			{
				printf("Give coordinates:");
				scanf("%s", ansr);
				y3= ansr[0]-97;
				if(ansr[2]=='\0')
				{
					x1=ansr[1]-48;
				}
				else
				{
					x1=(ansr[1]-48)*10+ansr[2]-48;
				}
				printf("%d %d\n",y3,x1);
			}while(checkmove(y3,x1)!=1);
		}
		else if(apa[0]==119 || apa[0]==87)//w
		{
			if(pl[trn][3]>0)
			{
				pl[trn][3]--;
			do
			{
				printf("Give coordinates:");
				scanf("%s", ansr2);
				y21=ansr2[0]-97;
				if(isdigit(ansr2[2]))
				{
					x21=(ansr2[1]-48)*10+ansr2[2]-48;
					y11=ansr2[3]-97;
					if(ansr2[5]=='\0')
					{
						x11=ansr2[4]-48;	
					}	
					else
					{
						x11=(ansr2[4]-48)*10+ansr2[5]-48;
					}
				}
				else
				{
					x21=ansr2[1]-48;
					y11=ansr2[2]-97;
					if(ansr2[4]=='\0')
					{
						x11=ansr2[3]-48;	
					}	
					else
					{
						x11=(ansr2[3]-48)*10+ansr2[4]-48;
					}
				}	
			}while(checkblock(y21,x21,y11,x11)!=1);
			postu=1;
			}
			else
			{
				printf("no more blox left \n");
				postu=0;	
			}
		}
		else if(y5==(101+120+105+116) || y5==(69+88+73+84))//exit
		{
			printf("end of game\n");
			ext=1;
			trn=players;
		}
		else if(y5==(104+101+108+112) || y5==(72+69+76+80))//help
		{
			movebot();
			trn--;	
		}
	}while(postu==0);
	}
		else//bot's turn
		{
		if(pl[trn][3]>0)
		{

			printf("Bot %c ",table[pl[trn][1]][pl[trn][0]]);
			mm=rand() % 11;
		//	printf("mm %d\n-->",mm);
			if(mm<=think()) ///elenxos an tou exoun mini alla walls
			{
				printf("move\n");
				movebot();
			}
			else
			{
				pl[trn][3]--;
				printf("block\n");
				botwall();	
			}
		}
		else
		{
			printf("move\n");
			movebot();
		}		
		}
		showTable(); ///show
		if(players==2)
		{
			if(pl[0][1]==1)
			{
				printf("Player %c won the game\n",table[pl[0][1]][pl[0][0]]);
				ext=1;
			}
			else if(pl[1][1]==N)
			{
				printf("Player %c won the game\n",table[pl[1][1]][pl[1][0]]);
				ext=1;
			}		
		}
		else if(pl[0][1]==1)
		{
			printf("Player %c won the game\n",table[pl[0][1]][pl[0][0]]);
			ext=1;
		}
		else if(pl[1][0]==0)
		{
			printf("Player %c won the game\n",table[pl[1][1]][pl[1][0]]);
			ext=1;
		}
		else if(pl[2][1]==N)
		{
			printf("Player %c won the game\n",table[pl[2][1]][pl[2][0]]);
			ext=1;
		}
		else if(pl[3][0]==N-1)
		{
			printf("Player %c won the game\n",table[pl[3][1]][pl[3][0]]);
			ext=1;
		}
		}//paixtis++

		}while(ext!=1);//exit
	free(table);
	return 0;	
}

void showTable()  // pikanas emfanisi
{
    int i,j;
	printf("\n   ");
	for(i=0; i<N; i++)
	{
	    printf("%3c",alphaba[i]);
	}
	printf("\n");
    for(i=1; i<=(3+(N*3)); i++)
	{
	    printf("-");
	}
	printf("\n");
    for(i=1; i<=N; i++)
	{
	    printf("%2d",(i));
	    printf("|");
	    printf("  ");
	    for(j=0; j<N; j++)
	    {
			printf("%c",table[i][j]);
			printf("  ");
	    }
	    printf("\n");
	}
}
int checkmove(int y2, int x2)
{
	int i=trn;
	if(y2>N-1 || x2>N || y2<0 || x2<1)
	{
		printf("out of bounce\n");
		return 0;
	}
	else if(table[x2][y2]=='.' && ((pl[i][1]-x2==1 || pl[i][1]-x2==-1) && pl[i][0]==y2) || ((pl[i][0]-y2==1 || pl[i][0]-y2==-1) && pl[i][1]==x2))
	{
		table[x2][y2]=table[pl[i][1]][pl[i][0]];
		table[pl[i][1]][pl[i][0]]='.';
		pl[i][0]=y2;
		pl[i][1]=x2;
		printf("Player %c moved",table[x2][y2]);
		return 1;
	}
	else
	{
		printf("Wrong inputs plz try again\n");
		return 0;
	}

}
int checkblock(int q1, int q2, int q3, int q4)
{	
	if(q1<0 || q1>N-1 || q2>N || q2<1 || q3<0 || q3>N-1 || q4>N || q4<1) 
	{
		printf("Out of bounce\n");
		return 0;
	}
	else if(table[q2][q1]=='.' && table[q4][q3]=='.'  && ((q1-q3==1 || q1-q3==-1 && q2==q4) || (q2-q4==1 || q2-q4==-1 && q1==q3))) //posotita touvlon
	{
		table[q2][q1]='X';
		table[q4][q3]='X';
		return 1;
	}
	else
	{
		printf("Wrong inputs plz try again\n");
		return 0;		
	}
}	
int think() //move or block
{
		int t,i;
	if(pl[trn][4]==3)  
	{
		if(pl[trn][0]>=(N/2))
		{
			for(i=0; i<players; i++)
			{
				if(i!=trn)
				{
					if(pl[i][4]==1 && pl[i][1]<=(N/2) )
					{
						t=6;
					}
					else if(pl[i][4]==2 && pl[i][1]>=(N/2))
					{
						t=6;
					}
					else if(pl[i][4]==3 && pl[i][0]>=(N/2))
					{
						t=6;
					}
					else if(pl[i][4]==4 && pl[i][1]<=(N/2))
					{
						t=6;
					}
					else
					{	
						t=8;
					}				
				}
			}	
		}
		else
		{
			for(i=0; i<players; i++)
			{
				if(i!=trn)
				{
					if(pl[i][4]==1 && pl[i][1]<=(N/2) )
					{
						t=4;
					}
					else if(pl[i][4]==2 && pl[i][1]>=(N/2))
					{
						t=4;
					}
					else if(pl[i][4]==3 && pl[i][0]>=(N/2))
					{
						t=4;
					}
					else if(pl[i][4]==4 && pl[i][1]<=(N/2))
					{
						t=4;
					}
					else
					{
						t=8;				
					}				
				}
			}	
		}
	}
	else if(pl[trn][4]==4)  
	{
		if(pl[trn][0]<=(N/2))
		{
			for(i=0; i<players; i++)
			{
				if(i!=trn)
				{
					if(pl[i][4]==1 && pl[i][1]<=(N/2) )
					{
						t=6;
					}
					else if(pl[i][4]==2 && pl[i][1]>=(N/2))
					{
						t=6;
					}
					else if(pl[i][4]==3 && pl[i][0]>=(N/2))
					{
						t=6;
					}
					else if(pl[i][4]==4 && pl[i][1]<=(N/2))
					{
						t=6;
					}
					else
					{	
						t=8;
					}				
				}
			}	
		}
		else
		{
			for(i=0; i<players; i++)
			{
				if(i!=trn)
				{
					if(pl[i][4]==1 && pl[i][1]<=(N/2) )
					{
						t=4;
					}
					else if(pl[i][4]==2 && pl[i][1]>=(N/2))
					{
						t=4;
					}
					else if(pl[i][4]==3 && pl[i][0]>=(N/2))
					{
						t=4;
					}
					else if(pl[i][4]==4 && pl[i][1]<=(N/2))
					{
						t=4;
					}
					else
					{
						t=8;				
					}				
				}
			}	
		}
	}
	else if(pl[trn][4]==2)
	{
		if(pl[trn][1]>=(N/2))
		{
			for(i=0; i<players; i++)
			{
				if(i!=trn)
				{
					if(pl[i][4]==1 && pl[i][1]<=(N/2) )
					{
						t=6;
					}
					else if(pl[i][4]==2 && pl[i][1]>=(N/2))
					{
						t=6;
					}
					else if(pl[i][4]==3 && pl[i][0]>=(N/2))
					{
						t=6;
					}
					else if(pl[i][4]==4 && pl[i][1]<=(N/2))
					{
						t=6;
					}
					else
					{	
						t=8;
					}				
				}
			}	
		}
		else
		{
			for(i=0; i<players; i++)
			{
				if(i!=trn)
				{
					if(pl[i][4]==1 && pl[i][1]<=(N/2) )
					{
						t=4;
					}
					else if(pl[i][4]==2 && pl[i][1]>=(N/2))
					{
						t=4;
					}
					else if(pl[i][4]==3 && pl[i][0]>=(N/2))
					{
						t=4;
					}
					else if(pl[i][4]==4 && pl[i][1]<=(N/2))
					{
						t=4;
					}
					else
					{
						t=8;				
					}				
				}
			}	
		}
	}
	
	return t;			
}
void movebot()//
{
	int z1,z2,z3,m2,m1;
		z3=pl[trn][4];
		z1=pl[trn][1];
		z2=pl[trn][0];
		m2= learn(z1,z2,z3); // placewall
		if(m2==2)
		{
			if(y5==(104+101+108+112) || y5==(72+69+76+80))
			{
				z1++;
				printf("Help results-->%c %d\n",alphaba[z2],z1);	
			}
			else
			{
				z1++;
				table[z1][pl[trn][0]]=table[pl[trn][1]][pl[trn][0]];
				table[pl[trn][1]][pl[trn][0]]='.';
				pl[trn][1]=z1;
			}
		}
		else if(m2==3)
		{
			if(y5==(104+101+108+112) || y5==(72+69+76+80))
			{
				z2++;
				printf("Help results-->%c %d\n",alphaba[z2],z1);	
			}
			else
			{			
				z2++;			
				table[z1][z2]=table[pl[trn][1]][pl[trn][0]];
				table[pl[trn][1]][pl[trn][0]]='.';
				pl[trn][0]=z2;
			}
		}
		else if(m2==4)
		{
			if(y5==(104+101+108+112) || y5==(72+69+76+80))
			{
				z2--;
				printf("Help results-->%c %d\n",alphaba[z2],z1);	
			}
			else
			{			
				z2--;
				table[z1][z2]=table[pl[trn][1]][pl[trn][0]];
				table[pl[trn][1]][pl[trn][0]]='.';							
				pl[trn][0]=z2;					
			}
		}
		else if(m2==1)
		{
			if(y5==(104+101+108+112) || y5==(72+69+76+80))
			{
				z1--;
				printf("Help results-->%c %d\n",alphaba[z2],z1);	
			}
			else
			{			
				z1--;
				table[z1][pl[trn][0]]=table[pl[trn][1]][pl[trn][0]];
				table[pl[trn][1]][pl[trn][0]]='.';
				pl[trn][1]=z1;	
			}
		}
		
}
int learn(int x11, int y11, int kt1)//out of bounce bot
{
	int r0,r1,r2,r3,r4,r5,e1=0,e2=0,i; 
	int n1,zq=0;
	
if(kt1==2)
{
		r5=x11+2;
		r4=y11-1;
		r3=y11+1;
		r2=y11;
		r1=x11+1;
		if(r1<=N && table[r1][r2]=='.')
		{
			return 2;							
		}
		else
		{
			for(i=r4; i>0; i--)
			{
				if(i>=0 && table[x11][i]=='.')//an h  thesi aristera wall einai telia
				{
					e1++;//poses .+prospathies aristera s
					
					if(table[r1][i]=='.')
					{
						i=-1;
					}
				}
				else
				{
					e1=N;
					i=-1;
				}
			}
			for(i=r3; i<N ; i++)
			{
			if(table[x11][i]=='.')
			{
				e2++;
				if(table[r1][i]=='.')
				{
					i=N;
				}
			}
			else
			{	
				e2=N;
				i=N;
			}
			}
		if((e1-e2<=0 || e2==0) && e1!=0)
		{
			return 4;
		}
		else 
		{
			return 3;
		}	
		}
	}
if(kt1==3)
{
	
		r5=y11+2;
		r4=x11-1;
		r3=y11+1;
		r2=x11;
		r1=x11+1;
		if(r3<N && table[r2][r3]=='.')
		{
			return 3;							
		}
		if(r3<N && table[r2][r3]!='.')
		{
			
			for(i=r4; i>0; i--)
			{
				if(i>=0 && table[i][y11]=='.')//an h  thesi aristera wall einai telia
				{
					e1++;//poses .+ prospathies aristera s
					
					if(table[i][y11]=='.')
					{
						i=-1;
					}
				}
				else
				{
					e1=N;
					i=-1;
				}
			}
			for(i=r1; i<N ; i++)
			{
			if(table[i][y11]=='.')
			{
				e2++;
				if(table[i][y11]=='.')
				{
					i=N;
				}
			}
			else
			{	
				e2=N;
				i=N;
			}
			}
		if((e1-e2<=0 || e2==0) && e1!=0)
		{
			return 2;
		}
		else 
		{
			return 1;
		}	
		}
	}
if(kt1==1)
{
	r5=x11+2;
	r4=y11-1;
	r3=y11+1;
	r2=y11;
	r1=x11-1;
		if(r1>=1 && table[r1][r2]=='.')
		{
			return 1;							
		}
		else
		{
			for(i=r4; i>0; i--)
			{
				if(i>=0 && table[x11][i]=='.')//an h  thesi aristera wall einai telia
				{
					e1++;//poses .+prospathies aristera s
					
					if(table[r1][i]=='.')
					{
						i=-1;
					}
				}
				else
				{
					e1=N;
					i=-1;
				}
			}
			for(i=r3; i<N ; i++)
			{
			if(table[x11][i]=='.')
			{
				e2++;
				if(table[r1][i]=='.')
				{
					i=N;
				}
			}
			else
			{	
				e2=N;
				i=N;
			}
			}
		if((e1-e2<=0 || e2==0) && e1!=0)
		{
			return 4;
		}
		else 
		{
			return 3;
		}	
		}
	}
if(kt1==4)
{
	
		r5=y11+2;
		r4=x11-1;
		r3=y11-1;
		r2=x11;
		r1=x11+1;
		if(r3>=0 && table[r2][r3]=='.')
		{
			return 4;									
		}
		if(r3>=0 && table[r2][r3]!='.')
		{
			
			for(i=r4; i>0; i--)
			{
				if(i>=0 && table[i][y11]=='.')//an h  thesi aristera wall einai telia
				{
					e1++;//poses .+ prospathies aristera s
					
					if(table[i][y11]=='.')
					{
						i=-1;
					}
				}
				else
				{
					e1=N;
					i=-1;
				}
			}
			for(i=r1; i<N ; i++)
			{
			if(table[i][y11]=='.')
			{
				e2++;
				if(table[i][y11]=='.')
				{
					i=N;
				}
			}
			else
			{	
				e2=N;
				i=N;
			}
			}
		if((e1-e2<=0 || e2==0) && e1!=0)
		{
			return 2;
		}
		else 
		{
			return 1;
		}	
		}
	}
}
void botwall()//ok
{
	int z0=0,u11=0;
	int stx[3]={0};
	int stx1[3]={0};
	int i;
	for(i=0; i<players; i++)
	{
		if(i!=trn)
		{
			stx[z0]=i;
			z0++;
			if(pl[i][4]==1 && pl[i][1]<=(N/2) )
			{
				stx1[u11]=i;
				u11++;
			}
			if(pl[i][4]==2 && pl[i][1]>=(N/2))
			{
				stx1[u11]=i;
				u11++;
			}
			if(pl[i][4]==3 && pl[i][0]>=(N/2))
			{
				stx1[u11]=i;
				u11++;
			}
			if(pl[i][4]==4 && pl[i][0]<=(N/2))
			{
				stx1[u11]=i;
				u11++;
			}
			
			else
			{	
				z0=2;
			}				
		}
	}	
	
	if(u11==1)
	{
		u11--;
		placewall(pl[stx1[u11]][1],pl[stx1[u11]][0],pl[stx1[u11]][4]);
	}
	else if(u11==2)
	{
		u11--;
		u11= rand() % 1;	
		placewall(pl[stx1[u11]][1],pl[stx1[u11]][0],pl[stx1[u11]][4]);
	}
	else
	{
		if(players==2)
		{
			placewall(pl[0][1],pl[0][0],pl[0][4]);
		}
		else
		{
			z0= rand() % 2;
			placewall(pl[stx[z0]][1],pl[stx[z0]][0],pl[stx[z0]][4]);
		}
	}			
}
void placewall(int x00, int y00, int kt)
{
	int r1,r2,r3,r4,r5,e1=0,e2=0,i;
	int n1;
if(kt==2)
{
		r5=x00+2;
		r4=y00-1;
		r3=y00+1;
		r2=y00;
		r1=x00+1;
		if(r1<=N && table[r1][r2]=='.')
		{
			if(r4>=0 && table[r1][r4]=='.')
			{
				table[r1][r2]='X';
				table[r1][r4]='X';
			}
			else if(r3<N && table[r1][r3]=='.')
			{
				table[r1][r2]='X';
				table[r1][r3]='X';				
			}
			else if(r5<=N && table[r5][r2]=='.')
			{
				table[r1][r2]='X';
				table[r5][r2]='X';
			}
			else 
			{
			i=r4;
			for(i>0; i--;)
			{
				if(table[r1][i]=='.')//an h  thesi aristera wall einai telia
				{
					if(checkwall(r1,i,kt)==1)
					{
						e1++;
						table[r1][i]=='X';
						i=0;
					}
					else
					{
						e1=0;
					}
				}
			}
			if(e1==0)
			{
				i=r3;
				for(i; i<N; i++)
				{
				if(table[r1][i]=='.')
				{
					if(checkwall(r1,i,kt)==1)
					{
						e1++;
						table[r1][i]=='X';
						i=0;
					}
					else
					{
						printf("full\n");
					}
				}
				}
			}
		}					
			
		}
		else
		{
			i=r4;
			for(i>0; i--;)
			{
				if(table[r1][i]=='.')//an h  thesi aristera wall einai telia
				{
					if(checkwall(r1,i,kt)==1)
					{
						e1++;
						table[r1][i]=='X';
						i=0;
					}
					else
					{
						e1=0;
					}
				}
			}
			if(e1==0)
			{
				i=r3;
				for(i; i<N; i++)
				{
				if(table[r1][i]=='.')
				{
					if(checkwall(r1,i,kt)==1)
					{
						e1++;
						table[r1][i]=='X';
						i=0;
					}
					else
					{
						printf("full\n");
					}
				}
				}
			}
		}
	}
	
	if(kt==1)
	{
		r5=x00-2;
		r4=y00-1;
		r3=y00+1;
		r2=y00;
		r1=x00-1;
		if(r1>=1 && table[r1][r2]=='.')
		{;
			if(r4>=0 && table[r1][r4]=='.')
			{
				table[r1][r2]='X';
				table[r1][r4]='X';
			}
			else if(r3<N && table[r1][r3]=='.')
			{
				table[r1][r2]='X';
				table[r1][r3]='X';				
			}
			else if(r5>=1 && table[r5][r2]=='.')
			{
				table[r1][r2]='X';
				table[r5][r2]='X';
			}
			else 
			{
			i=r4;
			for(i>=0; i--;)
			{
				if(table[r1][i]=='.')//an h  thesi aristera wall einai telia
				{
					if(checkwall(r1,i,kt)==1)
					{
						e1++;
						table[r1][i]=='X';
						i=0;
					}
					else
					{
						e1=0;
					}
				}
			}
			if(e1==0)
			{
				i=r3;
				for(i; i<N; i++)
				{
				if(table[r1][i]=='.')
				{
					if(checkwall(r1,i,kt)==1)
					{
						e1++;
						table[r1][i]=='X';
						i=0;
					}
					else
					{
						printf("full\n");//kleistike
					}
				}
				}
			}
			}
			
		}
		else
		{
			i=r4;
			for(i>0; i--;)
			{
				if(table[r1][i]=='.')//an h  thesi aristera wall einai telia
				{
					if(checkwall(r1,i,kt)==1)
					{
						e1++;
						table[r1][i]=='X';
						i=0;
					}
					else
					{
						e1=0;
					}
				}
			}
			if(e1==0)
			{
				i=r3;
				for(i; i<N; i++)
				{
				if(table[r1][i]=='.')
				{
					if(checkwall(r1,i,kt)==1)
					{
						e1++;
						table[r1][i]=='X';
						i=0;
					}
					else
					{
						printf("full\n");
					}
				}
				}
			}
		}
	}
if(kt==3)
{
		r5=x00+1;
		r4=x00;
		r3=y00+1;
		r2=y00+2;
		r1=x00-1;
		if(r3<N && table[r4][r3]=='.')
		{
			if(r1>=1 && table[r1][r3]=='.')
			{
				table[r1][r3]='X';
				table[r4][r3]='X';
			}
			else if(r5<=N && table[r5][r3]=='.')
			{
				table[r5][r3]='X';
				table[r4][r3]='X';				
			}
			else if(r2<N && table[r4][r2]=='.')
			{
				table[r4][r2]='X';
				table[r4][r3]='X';
			}
			else 
			{
			i=r1;
			for(i>0; i--;)
			{
				if(table[i][r3]=='.')//an h  thesi aristera wall einai telia
				{
					if(checkwall(i,r3,kt)==1)
					{
						e1++;
						table[i][r3]=='X';
						i=0;
					}
					else
					{
						e1=0;
					}
				}
			}
			if(e1==0)
			{
				i=r5;
				for(i; i<N; i++)
				{
				if(table[i][r3]=='.')
				{
					if(checkwall(i,r3,kt)==1)
					{
						e1++;
						table[i][r3]=='X';
						i=0;
					}
					else
					{
						printf("full\n");
					}
				}
				}
			}
			}					
			
		}
		else
		{
			i=r1;
			for(i>0; i--;)
			{
				if(table[i][r3]=='.')//an h  thesi aristera wall einai telia
				{
					if(checkwall(i,r3,kt)==1)
					{
						e1++;
						table[i][r3]=='X';
						i=0;
					}
					else
					{
						e1=0;
					}
				}
			}
			if(e1==0)
			{
				i=r5;
				for(i; i<N; i++)
				{
				if(table[i][r3]=='.')
				{
					if(checkwall(i,r3,kt)==1)
					{
						e1++;
						table[i][r3]=='X';
						i=0;
					}
					else
					{
						printf("full\n");
					}
				}
				}
			}
		}
	}

if(kt==4)
{
		r5=x00+1;
		r4=x00;
		r3=y00-1;
		r2=y00-2;
		r1=x00-1;
		if(r3>=0 && table[r4][r3]=='.')
		{
			if(r1>=1 && table[r1][r3]=='.')
			{
				table[r1][r3]='X';
				table[r4][r3]='X';
			}
			else if(r5<=N && table[r5][r3]=='.')
			{
				table[r5][r3]='X';
				table[r4][r3]='X';				
			}
			else if(r2<=0 && table[r4][r2]=='.')
			{
				table[r4][r2]='X';
				table[r4][r3]='X';
			}
			else 
			{
			i=r1;
			for(i>0; i--;)
			{
				if(table[i][r3]=='.')//an h  thesi aristera wall einai telia
				{
					if(checkwall(i,r3,kt)==1)
					{
						e1++;
						table[i][r3]=='X';
						i=0;
					}
					else
					{
						e1=0;
					}
				}
			}
			if(e1==0)
			{
				i=r5;
				for(i; i<N; i++)
				{
				if(table[i][r3]=='.')
				{
					if(checkwall(i,r3,kt)==1)
					{
						e1++;
						table[i][r3]=='X';
						i=0;
					}
					else
					{
						printf("full\n");
					}
				}
				}
			}
		}					
			
		}
		else
		{
			i=r1;
			for(i>0; i--;)
			{
				if(table[i][r3]=='.')//an h  thesi aristera wall einai telia
				{
					if(checkwall(i,r3,kt)==1)
					{
						e1++;
						table[i][r3]=='X';
						i=0;
					}
					else
					{
						e1=0;
					}
				}
			}
			if(e1==0)
			{
				i=r5;
				for(i; i<N; i++)
				{
				if(table[i][r3]=='.')
				{
					if(checkwall(i,r3,kt)==1)
					{
						e1++;
						table[i][r3]=='X';
						i=0;
					}
					else
					{
						printf("full\n");
					}
				}
				}
			}
		}
	}
}
int checkwall(int u1, int u2,int u3)
{
if(u3==2)
{
	u2--;
	if(u2>=0 && table[u1][u2]=='.')
	{
		table[u1][u2]=='X';
		return 1;
	}
	else
	{
		u2++;
		u2++;	
	}	
	if(u2<N && table[u1][u2]=='.')
	{
		table[u1][u2]=='X';
		return 1;
	}
	else
	{
		u1++;
		u2--;
	}
	if(u1<=N && table[u1][u2]=='.')
	{
		table[u1][u2]=='X';
		return 1;
	}
	else
	{
		u1-2;
	}
	if(u1>=1 && table[u1][u2]=='.')
	{
		table[u1][u2]=='X';
		return 1;
	}
	else
	{
		printf("Couldnt find: %d %d\n",u1,u2);
		return 0;
	}
}
else if(u3==1)
{
	u1--;
	if(u1>=1 && table[u1][u2]=='.')
	{
		table[u1][u2]=='X';
		return 1;
	}
	else
	{
		u1++;
		u1++;	
	}	
	if(u1<=N && table[u1][u2]=='.')
	{
		table[u1][u2]=='X';
		return 1;
	}
	else
	{
		u1++;
		u2--;
	}
	if(u2>=0 && table[u1][u2]=='.')
	{
		table[u1][u2]=='X';
		return 1;
	}
	else
	{
		u2++;
		u2++;
	}
	if(u2<N && table[u1][u2]=='.')
	{
		table[u1][u2]=='X';
		return 1;
	}
	else
	{
		printf("Couldnt find: %d %d\n",u1,u2);
		return 0;
	}
}
else if(u3==3)
{
	u1--;
	if(u1>=1 && table[u1][u2]=='.')
	{
		table[u1][u2]=='X';
		return 1;
	}
	else
	{
		u1++;
		u1++;	
	}	
	if(u1<=N && table[u1][u2]=='.')
	{
		table[u1][u2]=='X';
		return 1;
	}
	else
	{
		u1--;
		u2--;
	}
	if(u2>=0 && table[u1][u2]=='.')
	{
		table[u1][u2]=='X';
		return 1;
	}
	else
	{
		u2++;
		u2++;
	}
	if(u2<N && table[u1][u2]=='.')
	{
		table[u1][u2]=='X';
		return 1;
	}
	else
	{
		printf("Couldnt find: %d %d\n",u1,u2);
		return 0;
	}	
}
	else if(u3==4)
	{
	u1--;
	if(u1>=1 && table[u1][u2]=='.')
	{
		table[u1][u2]=='X';
		return 1;
	}
	else
	{
		u1++;
		u1++;	
	}	
	if(u1<=N && table[u1][u2]=='.')
	{
		table[u1][u2]=='X';
		return 1;
	}
	else
	{
		u1--;
		u2--;
	}
	if(u2>=0 && table[u1][u2]=='.')
	{
		table[u1][u2]=='X';
		return 1;
	}
	else
	{
		u2++;
		u2++;
	}
	if(u2<N && table[u1][u2]=='.')
	{
		table[u1][u2]=='X';
		return 1;
	}
	else
	{
		printf("Couldnt find: %d %d\n",u1,u2);
		return 0;
	}
		
	}
}
// 1 up 2 down 3 right 4 left      //fake table x x
