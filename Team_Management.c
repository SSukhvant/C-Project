#include<stdio.h>
void standings();
void addtm();
void searchtm();
void deltm();
void matches();
void team();
void addply();
void searchply();
void delply();
FILE *fp,*ft,*fp1,*ft1;
struct ipl
{
	char player[100],mt1[100],mt2[100];
	char tm[100];
	int sn,run,six,four;
	int tmn,m;
	int w,l,pts;
	float sr;
}s;
	
int main()
{
	int ch;
	while(1)
	{   printf("\n=============================================\n");
	    printf("<<<<<<<<<INDIAN-----PREMIUM-----LEAGE>>>>>>>>>>\n");
	    printf("===============================================\n");
		printf("\nSTANDINGS TEAM    :1\n");
		printf("ADD TEAM          :2\n");
		printf("SEARCH TEAM       :3\n");
		printf("DELETE TEAM       :4\n");
		printf("MATCHES B/W TEAMS :5\n");
		printf("TEAM DISPLAY      :6\n");
		printf("ADD PLAYER        :7\n");
		printf("SEARCH PLAYER     :8\n");
		printf("DELETE PLAYER     :9\n");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1:
		    standings();
		    break;
		case 2:
		    addtm();
		    break;
		case 3:
		    searchtm;
		    break;
		case 4:
		    deltm();
		    break;
		case 5:
		    matches();
		    break;
		case 6:
		    team();
		    break;
		case 7:
			addply();
			break;
		case 8:
			searchply();
			break;
		case 9:
		    delply();
		    break;
	    }
	}
}
void standings()
{
	fp = fopen ( "data.dat", "rb" );
    printf("===============================================================\n");
    printf(" S.N   TEAM                  MATCH  WIN  LOSE  POINTS          \n");
    printf("===============================================================\n");
    while ( fread ( &s,sizeof(s), 1, fp ) == 1 )
    printf ("\n%3d   %8s %20d %4d %5d %14f",s.tmn,s.tm,s.m,s.w,s.l,s.pts);
    fclose(fp);
}
void addtm()
{   struct ipl s;
	printf("ENTER TEAM NO.: ");
	scanf("%d",&s.tmn);
    printf("ENTER NAME OF TEAM: ");
	scanf("%s",s.tm);
	printf("ENTER TOTAL MATCHES: ");
	scanf("%d",&s.m);
	printf("ENTER TOTAL WIN MATCHES: ");
	scanf("%d",&s.w);
	printf("ENTER TOTAL LOSE MATCHES: ");
	scanf("%d",&s.l);
	printf("ENTER POINTS: ");
	scanf("%d",&s.pts);
	fp=fopen("data.dat","ab");
	fwrite(&s,sizeof(s),1,fp);
	fclose(fp);
}
void searchtm()
{
	int tmno,flag=0;
	printf("ENTER TEAM NAME TO SEARCH :");
	scanf("%s",&tmno);
	fp=fopen("data.dat","rb");
	rewind(fp);
	while ( fread ( &s, sizeof(s), 1, fp ) == 1 )
    {
        if ( s.tmn==tmno)
        {
           printf ("\n%s  %d  %d  %d  %f",s.tmn,s.tm,s.m, s.w,s.l,s.pts);
           flag=1;
        }
	}
    if(flag==0)printf("Data not found");
    fclose ( fp ) ;
     	
}
void deltm()
{
	int tmno;
	printf("Enter player serial no to delete :");
	scanf("%d",&tmno);
	fp=fopen("data.dat","rb");
	ft=fopen("temp.dat","wb");
	rewind(fp);
	while ( fread ( &s, sizeof(s), 1, fp ) == 1 )
    {
        if ( s.tmn!=tmno)
        fwrite ( &s, sizeof(s), 1, ft ) ;
    }
    fclose ( fp ) ;
    fclose ( ft ) ;
    remove ( "data.dat" ) ;
    rename ( "temp.dat", "data.dat" ); 
	
}
void matches()
{
	struct ipl match[100];
    int i;
    for(i=0;i<1;i++)
{
	printf("\nTEAM 1");
	scanf("%s",match[i].mt1);
	printf("\nTEAM 2");
	scanf("%s",match[i].mt2);
}
    printf("================================================\n");
    printf("      T1               VS                T2     \n");
    printf("================================================\n");
   for(i=0;i<1;i++)
{
    printf("%7s  %33s",match[i].mt1,match[i].mt2);
}
}

void team()
{
	fp1 = fopen ( "data.dat", "rb" );
    printf("===============================================================\n");
    printf(" S.N      PLAYER                  RUN   SIX   FOUR   S/R       \n");
    printf("===============================================================\n");
    while ( fread ( &s,sizeof(s), 1, fp1 ) == 1 )
    printf ("\n%3d   %8s %20d %4d %5d %14f",s.sn,s.player,s.run,s.six,s.four,s.sr);
    fclose(fp1);
}
void addply()
{
    printf("Enter serial: ");
	scanf("%d",&s.sn);
	printf("Enter player name: ");
	scanf("%s",s.player);

	printf("Enter run: ");
	scanf("%d",&s.run);
	printf("Enter six: ");
	scanf("%d",&s.six);
	printf("Enter four: ");
	scanf("%d",&s.four);
	printf("Enter strike rate: ");
	scanf("%f",&s.sr);
	fp1=fopen("data.dat","ab");
	fwrite(&s,sizeof(s),1,fp1);
	fclose(fp1);
}
void searchply()
{
	int serial,flag=0;
	printf("Enter serial no. to search :");
	scanf("%s",&serial);
	fp1=fopen("data.dat","rb");
	rewind(fp1);
	while ( fread ( &s, sizeof(s), 1, fp1 ) == 1 )
    {
        if ( s.sn==serial)
        {
           printf ("\n%s  %d  %d  %d  %f",s.sn,s.player, s.run,s.six,s.four,s.sr);
           flag=1;
        }
	}
    if(flag==0)printf("Data not found");
    fclose ( fp1 ) ;
     	
}
void delply()
{
	int serial;
	printf("Enter player serial no to delete :");
	scanf("%d",&serial);
	fp1=fopen("data.dat","rb");
	ft1=fopen("temp.dat","wb");
	rewind(fp);
	while ( fread ( &s, sizeof(s), 1, fp ) == 1 )
    {
        if ( s.sn!=serial)
        fwrite ( &s, sizeof(s), 1, ft1 ) ;
    }
    fclose ( fp1 ) ;
    fclose ( ft1 ) ;
    remove ( "data.dat" ) ;
    rename ( "temp.dat", "data.dat" ); 
	
}



