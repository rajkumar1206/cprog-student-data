#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include<ctype.h>

//#include<fstream.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct signup{
	char name[50];
	int	age;
	long phone;
	char emaild[50];
	char college[50];
	char regno[50];
	char branch[50];
	int semester;
	char password[50];
	char lang[50];
	char cgpa[20];
	int id;

};
int count=0;
struct userinternship{
	int idi;
	int userid;
	int internid;
	int batch;
}userin;

struct internship
{
    int id;
    char name[50];
    char dis[50];
    char req[50];
    char branch[50];
    int sem;
    int std;
    
}in;

struct node {
	int data;
	int linkedid;
	int internid1;
	int idi1;
	struct node * link;
};




/*struct node1 {
	int data1;
	int linkedid1;
	struct node1 * link1;
};*/


int checkstring(char *a,char *b)

{ // Returns true if a is substring of b 
    int M,N;
    for(M=0;a[M]!='\0';M++);
     for(N=0;b[N]!='\0';N++);
      int i,j; 
 // printf("\nHI in checkstring\n");
  
    for ( i = 0; i <= N - M; i++) { 
      
  
        
        for (j = 0; j < M; j++) 
            if (b[i + j] != a[j]) 
                break; 
  
        if (j == M) 
            return 1; 
    } 
  
    return 0;
} 
		
	

int	checkbranch(int usd,int iid)
{
	struct internship s4;
	struct signup u2;
	FILE *intern,*us;
	int f=0;
//	printf("\nHI in checkbranch\n");
	intern=fopen("internship.txt","r");
	us=fopen("user.txt","r");
	while(fread(&u2,sizeof(struct signup),1,us))
	{
		if(u2.id==usd)
		{
			f=1;
			break;
		}
	}
	if(f==1)
	{
		while(fread(&s4,sizeof(	struct internship),1,intern))
		{
			if(iid==s4.id)
			{
				if(checkstring(u2.branch,s4.branch))
				{
					return 1;
				}
			}
		}
	}
	fclose(us);
	fclose(intern);
	return 0;
}
int checksem(int usdt,int iidt)
{
	struct internship st4;
	struct signup ut2;
	FILE *internt,*ust;
	
	int ft=0;
//	printf("\nHI in checkbranch\n");
	internt=fopen("internship.txt","r");
	ust=fopen("user.txt","r");
	while(fread(&ut2,sizeof(struct signup),1,ust))
	{
		if(ut2.id==usdt)
		{
			ft=1;
			break;
		}
	}
	if(ft==1)
	{
		while(fread(&st4,sizeof(	struct internship),1,internt))
		{
			if(iidt==st4.id)
			{
				if(ut2.semester==st4.sem)
				{
					return 1;
				}
			}
		}
	}
	fclose(ust);
	fclose(internt);
	return 0;
	
	
}




void append ( struct node **q, int num ,int linkid,int intern2,int idiii)
{
	
	struct node *NN,*tempp;
	NN=(struct node *)malloc(sizeof(struct node));
	NN->data=num;
	NN->linkedid=linkid;
	NN->link=NULL;
	NN->idi1=idiii;
	NN->internid1=intern2;
	
	tempp=*q;
	if(tempp==NULL)
	    *q=NN;
	    
	else
	    {
	        while(tempp->link!=NULL)
	            {
	                tempp=tempp->link;
	            }
	           
	       tempp->link=NN;
	    }
}
/*void append1 ( struct node1 **q1, int num1 ,int linkid1)
{
	
	struct node1 *NN1,*tempp1;
	NN1=(struct node1 *)malloc(sizeof(struct node1));
	NN1->data1=num1;
	NN1->linkedid1=linkid1;
	NN1->link1=NULL;
	
	tempp1=*q1;
	if(tempp1==NULL)
	    *q1=NN1;
	    
	else
	    {
	        while(tempp1->link1!=NULL)
	            {
	                tempp1=tempp1->link1;
	            }
	           
	       tempp1->link1=NN1;
	    }
}

void addatbeg ( struct node1 **q1, int num1)
{
	struct node1 * NN1, *temp1;
	
	temp1=*q1;
	
	NN1=(struct node1 *)malloc(sizeof(struct node1));
	NN1->data1=num1;
//	NN1->linkedid=linkid;
	NN1->link1=temp1;
	*q1=NN1;
	
}*/


void display ( struct node *q ){
	
	if(q==NULL)
	    printf("No elements in the list\n");
	   
	while(q!=NULL)
	    {
	    	printf("%d ",q->linkedid);
	        
	        printf("%d ",q->internid1);
	        printf("%d ",q->idi1);
	        
	        printf("%d \n",q->data);
	        
	        q=q->link;
	    }
}





void rewrite(struct node *head)
{
	
	struct node* temp0;
   FILE *outfile; 
   struct userinternship t;
        //struct node input;
    // open file for writing 
        outfile = fopen ("alldata.txt", "w"); 
      
      // write struct to file 
           temp0 = head;
          while(temp0!= NULL)
         {
         	//struct node input=*temp;
         //	printf("id %d userid %d internshipid %d batch %d \n",temp->id,temp->userid,temp->internshipid,temp->batch);
         	t.idi=temp0->idi1;
         	t.batch=temp0->data;
         	t.internid=temp0->internid1;
         	t.userid=temp0->linkedid;
            fwrite (&t, sizeof(struct userinternship), 1, outfile); 
    
           temp0 = temp0->link;  
          }
         // close file 
         fclose (outfile);
	
}

void readfun()
	{
		FILE *refile;
		
		refile=fopen("alldata.txt","r");
		struct userinternship reading;
		
		while(fread(&reading,sizeof(struct userinternship),1,refile))
		{
			printf("%d %d %d %d\n",reading.idi,reading.internid,reading.userid,reading.batch);
			
		}
		
		fclose(refile);
	}




void admin()
{
	int choice,choice1,criteria;
	printf("Welcome Admin!\n\n");
	
	int tempcri;
	printf("1.Add Internship\n");
	printf("2.Create Batch\n");
	printf("3.Exit\n");
	printf("Enter your choice:\n");
	
	
	scanf("%d",&choice);

	if(choice==1)
		{
				FILE *adm;
	int tot;
	adm=fopen("internship.txt","a");
	do
	{
	
	printf("Id:\n");
	scanf("%d",&in.id);
	printf("Name:\n");
	scanf(" %[^\n]s",in.name);
	printf("Description:\n");
	scanf(" %[^\n]s",in.dis);
	printf("Requirement:\n");
	scanf(" %[^\n]s",in.req);
	printf("Branch:\n");
	scanf(" %[^\n]s",&in.branch);
	printf("Semester:\n");
	scanf("%d",&in.sem);
	printf("StudentsPerBatch:\n");
	scanf("%d",&in.std);
	
	fwrite(&in,sizeof(struct internship),1,adm);
	
	printf("Successful\n"); 
	printf("Enter 1 to enter more data:\n");
	scanf("%d",&tot);
	
	
	}while(tot==1);
	fclose(adm);
		}
	//	fclose(adm);
	if(choice==2)
		{
			FILE *opo;
		
	opo=fopen("internship.txt","r");
	printf("Select Internship\n");
	while(fread(&in,sizeof(in),1,opo)>0)
		{
			printf("%d. ",in.id);
			printf("%s\n",in.name);
		}
	fclose(opo);
		
		printf("Enter your internship choice\n");
		scanf("%d",&choice1);
		FILE *fp3;
		fp3=fopen("internship.txt","r");
		struct internship inchoice;
	    while(fread(&inchoice,sizeof(struct internship),1,fp3))
	    {
	    	if(inchoice.id==choice1)
	    	{
			//	printf("Selected Internshipid : %d \n",inchoice.id);
	         	break;
		    }
		}
			fclose(fp3);
	choose:	printf("Choice criteria\n");
		printf("1.First in First\n");
		printf("2.Based on branch\n");
		printf("3.Based on semester\n");
		printf("4.Finalize batch\n");
		
		printf("Enter your choice\n");
		scanf("%d",&criteria);
		
		struct node *p;
			//	p=NULL;
		
		
		if(criteria==1)
			{
				tempcri=1;
			//	printf("65656");
				FILE *add1;
			//	struct node *p;
				p=NULL;
				int counter1=0,b=1000*choice1;
				add1=fopen("alldata.txt","r");
				struct userinternship adm11;
				//struct internship inii;
				while(fread(&adm11,sizeof(struct userinternship),1,add1)>0)
					{
						//printf("ss");
						if(choice1==adm11.idi)
							{
								//adm11.batch=b;
								append(&p,b,adm11.userid,adm11.internid,adm11.idi);
								counter1++;
								
								//printf("%d\n",in.std);
								
								if(counter1==in.std)
								{
									counter1=0;
									b=b+1;
									
									//printf("88888\n");
								}
									//		b=b+1;
								
								
							//	printf("%d  \t",adm11.batch);
							//	printf("%d \t",adm11.internid);
							//	printf("%d  \n",adm11.userid);
								
							}
						
					}
					fclose(add1);
					
					FILE *a_p;
					a_p=fopen("alldata.txt","r");
				while(fread(&adm11,sizeof(struct userinternship),1,a_p)>0)
				{
					if(choice1!=adm11.idi)
					{
						append(&p,0,adm11.userid,adm11.internid,adm11.idi);
					}
				}
				
				fclose(a_p);
					
				
				
				display(p);
			/*	FILE *loo;
				loo=fopen("alldata.txt","a");
				fwrite(&adm11,sizeof(adm11),1,loo);
				fclose(loo);*/
			}
	
	struct node *p1;
			//	p1=NULL;
			
			
		if(criteria==2)
			{
				tempcri=2;
				
				//struct node *p1;
				p1=NULL;
					int count2=0,b2=1000*choice1;
		
		printf("\n");
		FILE *f;
		f=fopen("alldata.txt","r");
	//	struct node1 *p2;
	//	p2=NULL;
		struct userinternship s2;
		//	printf("Selected Internshipid : %d \n",inchoice.id);
		while(fread(&s2,sizeof(struct userinternship),1,f)>0)
		{
			//	printf("\nHI in admin  ");
			//		printf(" UserId : %d  Internshipid : %d \n",s2.userid,s2.idi);
				
			if(s2.idi==inchoice.id)
			{
				if(checkbranch(s2.userid,inchoice.id))
				{
					//
					s2.batch=b2;
				//	addatbeg(&p2,b2);
				append(&p1,b2,s2.userid,s2.internid,s2.idi);
					count2++;
					
					if(count2==inchoice.std)
					{
						count2=0;
						b2++;
					}
				//	printf("Student selected in interniship UserId : %d  InternishipId : %d Batch : %d\n",s2.userid,inchoice.id,s2.batch);
				//	return;
				}
			
			}
		}
		fclose(f);
		
		FILE *f1;
		f1=fopen("alldata.txt","r");
				
				while(fread(&s2,sizeof(struct userinternship),1,f1)>0)
					{
						if(s2.idi==inchoice.id)
			{
				if(checkbranch(s2.userid,inchoice.id)==0)
				{
					//
					append(&p1,b2,s2.userid,s2.internid,s2.idi);
				//	s2.batch=b2;
				//	printf("%d",b2);
				//	addatbeg(&p2,b2);
					count2++;
					
					if(count2==inchoice.std)
					{
						count2=0;
						b2++;
					}
				//	printf("Student selected in interniship UserId : %d  InternishipId : %d Batch : %d\n",s2.userid,inchoice.id,s2.batch);
					}
					
			}
	}
			fclose(f1);
			
			FILE *ji;
			
			ji=fopen("alldata.txt","r");
			
			while(fread(&s2,sizeof(struct userinternship),1,ji)>0)
			{
				if(s2.idi!=inchoice.id)
					{
						append(&p1,0,s2.userid,s2.internid,s2.idi);
						
					}
			}
			fclose(ji);
			
			
			
			display(p1);
		
			}
			struct node *p2;
		//p2=NULL;
			
			if(criteria==3)
			{
				
				tempcri=3;
					int countt2=0,bt2=1000*choice1;
		
		printf("\n");
		FILE *ft;
		ft=fopen("alldata.txt","r");
	//	struct node *p2;
		p2=NULL;
		struct userinternship st2;
		//	printf("Selected Internshipid : %d \n",inchoice.id);
		while(fread(&st2,sizeof(struct userinternship),1,ft)>0)
		{
			//	printf("\nHI in admin  ");
			//		printf(" UserId : %d  Internshipid : %d \n",s2.userid,s2.idi);
				
			if(st2.idi==inchoice.id)
			{
				if(checksem(st2.userid,inchoice.id))
				{
					//
					//st2.batch=bt2;
				//	addatbeg(&p2,b2);
					append(&p2,bt2,st2.userid,st2.internid,st2.idi);
					countt2++;
					
					if(countt2==inchoice.std)
					{
						countt2=0;
						bt2++;
					}
				//	printf("Student selected in interniship UserId : %d  InternishipId : %d Batch : %d\n",st2.userid,inchoice.id,st2.batch);
				//	return;
				}
			
			}
		}
		fclose(ft);
		
		FILE *ft1;
		ft1=fopen("alldata.txt","r");
				
				while(fread(&st2,sizeof(struct userinternship),1,ft1)>0)
					{
						if(st2.idi==inchoice.id)
			{
				if(checksem(st2.userid,inchoice.id)==0)
				{
					//
				//	st2.batch=bt2;
					append(&p2,bt2,st2.userid,st2.internid,st2.idi);
				//	printf("%d",b2);
				//	addatbeg(&p2,b2);
					countt2++;
					
					if(countt2==inchoice.std)
					{
						countt2=0;
						bt2++;
					}
				//	printf("Student selected in interniship UserId : %d  InternishipId : %d Batch : %d\n",st2.userid,inchoice.id,st2.batch);
					}
					
			}
	}
			fclose(ft1);
			
			FILE *ji1;
			
			ji1=fopen("alldata.txt","r");
			
			while(fread(&st2,sizeof(struct userinternship),1,ji1)>0)
			{
				if(st2.idi!=inchoice.id)
					{
						append(&p2,0,st2.userid,st2.internid,st2.idi);
						
					}
			}
			fclose(ji1);
			
			
			
			display(p2);
		
			}
			
			
			if(criteria==4)
			{
				//printf("dd");
				if(tempcri==1)
					{
						
						rewrite(p);
						printf("IN THE LIST\n");
						display(p);
						printf("\n\nIN THE FILE");
						
						readfun();
					}	
					
				if(tempcri==2)
					{
						rewrite(p1);
						printf("IN THE LIST\n");
						display(p1);
						printf("\n\nIN THE FILE");
						
						readfun();
					}
					
				if(tempcri==3)
				{
					rewrite(p2);
					printf("IN THE LIST\n");
					display(p2);
					printf("\n\nIN THE FILE\n");
						
						readfun();
				}
					
				
				return;
			}
			

	}
		
		
		
		
		
		
	if(choice==3)
		return;
	
goto choose;
	
}



void day2(struct signup *so )
{
		
	FILE *op;
	op=fopen("internship.txt","r");
	
	while(fread(&in,sizeof(struct internship),1,op)>0)
		{
			printf("%d. ",in.id);
			printf("%s\n",in.name);
		/*	printf("%d\n",in.sem);
			printf("%s\n",in.dis);*/
		}
		fclose(op);
		FILE *new;
		new=fopen("alldata.txt","r");
	printf("Enter your choice\n");
	//int cho;
	int k,flag12;
//	struct userinternship newdata;
	scanf("%d",&k);
	
	//int t=0;
	int t=so->id;
	//printf("%d\n",t);
	int flagg=1;
	if(new!=NULL)
	{
	while(fread(&userin,sizeof(userin),1,op)>0)
	{
	//	flag12=1;
		if(t==userin.userid)
			{
				printf("Already enrolled!\n");
				flagg++;
				return;
		}
			
	}
	fclose(new);
}
flag12=1;
FILE *nw;

struct userinternship trav;
nw=fopen("alldata.txt","r");
	
	while(fread(&trav,sizeof(trav),1,nw)>0)
	{
		if(k==trav.idi)
			flag12++;
	}
	fclose(nw);
	new=fopen("alldata.txt","a+");
	
	
	
		userin.userid=t;
		userin.internid=(flag12+(100)*k);
		userin.idi=k;
		//printf("%d\n",userin.userid);
		printf("%d\n",userin.internid);
		
	fwrite(&userin,sizeof(userin),1,new);
	printf("You are enrolled in %d as %d\n",userin.idi,userin.userid);
	fclose(new);		
}

//FILE *fp;
//fp=fopen("user.txt","w");

int valemail(char *email)
	{
		int i,j,c=0,d=0;
		for(i=0;email[i]!='\0';i++)
		{
			if(email[i]=='@')
			{
				c++;
				for(j=i+1;email[j]!='\0';j++)
				{
					if(email[j]=='.')
					d++;
				}
			}
		}
		if(c==1&&d>=1)
		return 1;
		else
		return 0;
	}
	
	int checkmail(char *email)
		{
		//	count=0;
			FILE *pp;
			struct signup si;
			pp=fopen("user.txt","r");
        while(fread(&si,sizeof(si),1,pp)){
        //	count++;
        //	printf("kjkjkjk\n");
        //	printf("%s\n",si.emaild);
            if(strcmp(si.emaild,email)==0)
			{
				
				fclose(pp);
				return 0;
		}
		}
	fclose(pp);
        return 1;
	}
	
	int valpass(char *pas)
	{
		int i,a=0,b=0,c=0,d=0;
		for(i=0;pas[i]!='\0';i++)
		{
			if(isalpha(pas[i])&&islower(pas[i]))
			{
				a++;
			}
			else if(isalpha(pas[i])&&isupper(pas[i]))
			{
				b++;
			}
			else if(isdigit(pas[i]))
			{
				c++;
			}
			else
			d++;

		}
		if(a>=2&&b>=2&&c>=2&&d>=2)
		{
			return 1;
		}
		else
		return 0;
	}
	
	int validateRN(char rn[50])
{
    if(rn[0]=='\0')
    {
        printf("Registration number can't be empty! Reenter registration number\n");
        return 0;

    }
    else if((rn[0]=='4' && rn[1]=='N' && rn[2]=='I') || (rn[0]=='4' && rn[1]=='M' && rn[2]=='H') || (rn[0]=='4' && rn[1]=='V' && rn[2]=='V') || (rn[0]=='4' && rn[1]=='G' && rn[2]=='S') || (rn[0]=='0' && rn[1]=='1' && rn[2]=='J' && rn[3]=='S' && rn[4]=='T'))
    {
        return 1;

    }
    else
    {
        printf("Entered registration number doesn't belong to list\n");
        return 0;
    }
}

void signup(struct signup *s)
	{
		FILE *fp;
		fp=fopen("user.txt","a");
	name:	printf("Enter the name\n");
		//scanf(" %s",s->name);
		//printf("\n");
		getchar();
		gets(s->name);
		if(strcmp(s->name,"")==0)
			{
				printf("Name can't be empty! Re-enter Name\n");
				goto name;
			}
			char age2[50];
			int t,i;
			s->age=0;
	age: printf("Enter the age\n");
		scanf("%s",age2);
			for(i=0;age2[i]!='\0';i++)
				{
					if(!(age2[i]>=48&&age2[i]<=57))
						{
							printf("Age should be numeric's\n");
							goto age;
						}
						else
						{
							t=age2[i]-48;
							s->age=s->age*10+t;
						}
					
				}
	emailid: printf("Enter the Email ID\n");
		    scanf("%s",s->emaild);
		    if(!valemail(s->emaild))
		    	{
		    		//printf("Jjjjj");
		    		printf("Enter a valid email id\n");
		    		goto emailid;
				}
			if(checkmail(s->emaild)==0)
				{
				//	printf("kjkjkj");
					printf("Enter a new email id\n");
					goto emailid;
				}
					
				
	char ph[50];
	s->phone=0;
	phonee:
			printf("Enter the phone number\n");
			scanf("%s",ph);
			
		    for(i=0;ph[i]!='\0';i++)
				{
					if(isalpha(ph[i]) || strlen(ph)!=10)
						{
							printf("Phone number should consists 10 digit only\n");
							goto phonee;
						}
						else
						{
							t=ph[i]-48;
							s->phone=s->phone*10+t;
						}
			}
	collegee : printf("Enter the college name\n");
	getchar();
	gets(s->college);
		//	scanf("%s",s->college);
		if(strcmp(s->college,"")==0)
			{
				printf("Name can't be empty! Re-enter Name\n");
				goto collegee;
			}	
	
	/*reg : printf("Enter the regstration number\n");
			scanf("%s",s->regno);*/
			
	 printf("Enter college registration number\n");
	 char RN[50];
    RN1:
    scanf("%s",RN);
    if(validateRN(RN))
    {
        s->regno;
    }
    else
    {
        //printf("Entered registration number doesn't belong to list");
        goto RN1;
    }
	
	branchh: printf("Enter the branch\n");
			scanf(" %[^\n]s",s->branch);
		//	gets(s->branch);
			char br[50];
			strcpy(br,strlwr(s->branch));
		
			if(strcmp(br,"computer science")!=0&&strcmp(br,"information science")!=0&&strcmp(br,"electronics and communication")!=0&&strcmp(br,"electrical ")!=0&&strcmp(br,"electronics and instrumentation")!=0)
				{
					printf("Entered branch doesn't belong to the list\n");
					goto  branchh;
				}
	char sems[10];
	sem: printf("Enter the semester\n");
		scanf("%s",sems);
		t=sems[0]-48;
		 
					if(t>8 || strlen(sems)!=1)
						{
							printf("Semester should be less than 8\n");
							goto sem;
						}
						else
						{
							s->semester=t;
							//s->semester=s->semester*10+t;
						}
	pass: printf("Enter a password\n");
		scanf("%s",s->password);
		if(!valpass(s->password))
			{
				printf("Password must consists of at least 2[A-Z], 2[a-z],2[!@..+*] and 2[0-9] character\n");
				goto pass;
			}
			
		char conpass[50];
	confpass : printf("Re-Enter your password\n");
			scanf("%s",conpass);
			if(strcmp(conpass,s->password)!=0)
				{
					printf("Password's doesn't match\n");
					goto confpass;
				}
	
	printf("Enter languages known\n");
	char lan[50];
            scanf("%s",lan);
        strcpy(s->lang,lan);
        
        
	cg: printf("Enter your Cgpa\n");
		//char s->cgpa;
		scanf("%s",s->cgpa);
		
		//if(s->cgpa==)
		
		if(s->cgpa[0]<48||s->cgpa[0]>57||s->cgpa[1]!=46||s->cgpa[2]<48||s->cgpa[2]>57||s->cgpa[3]<48||s->cgpa[3]>57)
    		{
    				printf("CGPA should be less than 10 and numeric value\n");
                   	goto cg;
			}
                               	
	/*	if(isdigit(s->cgpa[0]))
			{
				printf("CGPA should be less than 10 and numeric value\n");
				
			}*/
		//count++;
		fseek(fp, 0, SEEK_END);
		int filesize=ftell(fp);
		s->id=(filesize/sizeof(struct signup))+1;
			//printf("%d",s->id);
		fwrite(s,sizeof(struct signup),1,fp);
		
		//fprintf(fp,"\n");	
		fclose(fp);
}
	
	void signin()
	{
		FILE *ko;
		//int flag=0;
		char mail[50],pass[50];
		struct signup so;
		ko=fopen("user.txt","r");
 	printf("Enter Email\n");
 	getchar();
em:	gets(mail);


char apass[50];
	if(strcmp(mail,"admin")==0)
		 		{
		 			printf("Enter Password\n");
		 			scanf("%s",apass);
		 			if(strcmp(apass,"admin")==0)
		 			{
		 				//printf("Admin status approved");
		 				admin();
		 				return ;
					 }
		 			
				 }
	 else if(!valemail(mail))
		    	{
		    		//printf("Jjjjj");
		    		printf("Enter a valid email id\n");
		    		goto em;
				}
	//printf("ddd");
	//char apass[50];
	
	/*if(strcmp(mail,"admin@a.com")==0)
		 		{
		 			printf("Enter Password\n");
		 			scanf("%s",apass);
		 			if(strcmp(apass,"admin")==0)
		 			{
		 				//printf("Admin status approved");
		 				admin();
		 				return ;
					 }
		 			
				 }*/
				 
		 while(fread(&so,sizeof(so),1,ko)>0)
		 {
		 	
		 	
		 	 if(strcmp(so.emaild,mail)==0)
		 		{
		 			printf("Enter password\n");
				p:	scanf("%s",pass);
					if(strcmp(pass,so.password)!=0)
						{
							printf("Password does not match! Re-Enter password\n");
							goto p;
						}
					else
						{
							
							printf("Sign in successful\n");
							fclose(ko);
							day2(&so);
							return ;
						}
				}
			
		 }
		 
		 printf("User does not exist\nRe-Enter Email\n");
		 fseek(ko, 0, SEEK_SET);
		 goto em;
		// printf("User does not exist\n");
		 //goto em;

    }
 
int main(int argc, char *argv[]) {

	struct signup u;
	int ch;
	printf("1.Sign up\n2.Sign in\n3.Exit\n");
	scanf("%d",&ch);
	//do{
	
	switch(ch){
		case 1:	signup(&u);
		break;
		case 2: signin();
		break;
		case 3: printf("\nThank you\n");
				
	}
//}
//while(1);
	return 0;
}
