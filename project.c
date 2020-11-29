#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int delcntbr=0,delcntsm=0;
struct intern
{
    int id;
    char name[50];
    char des[100];
    char req[20];
    char bran[50];
    int sem;
    int spb;

};
struct ui
{
    int inid;
    int userid;
    int uiid;
    char batch[50];
};
struct uii
{
    int usid;
    struct uii* link;
};
struct uii *headd=NULL,*headd1=NULL;
struct u
{

    int id;
    char name[50];
    int age1;
    char phoneNumber[50];
    char emaild[50];
    char collegeName[50];
    char registrationNumber[50];
    char branch[50];
    int sem ;
    char password[50];
    char language[50];
    float cgpa;
};
struct node
{
    int inidn;
    int useridn;
    int uiidn;
    char batchn[50];
    struct node *link;

};
struct node *head=NULL;
int validatebranch(char* );
int validateregno(char*);
int validateage(float age);
int validatecgpa(float cgpa);
int validatephno(char* );
int validatepass(char*);
int validateemail(char*);
int checkmail(char*);
int checkusn(char*);
 void signup(struct u);
 void signin();
 void adminui();
 void addint();
 void addbtch();
 void chkin();
 void chkid(int,int);
 void usint();
 void cplink(int);
 void display();
 void addnode(struct ui);
 void srtbc(int);
 void srtsm(int);
 void dislst();
int main()
{
    int n;
    char email[50],college[50],RN[50],branch1[50],pass1[50],lan[50];
    float cgpa1;
    float age1;
    char name1[25];
    struct u user;
    FILE *ptr;
   // ptr = fopen("user.txt" ,"a+ ");
    printf("1.Signin\n2.SignUp\nEnter your choice\n");
    scanf("%d",&n);
    if(n==2)
    {
    float age;
    char phno[20];
    char name1[25];
    printf("Enter Name\n");
    rename :
        getchar();
    gets(name1);
    if(name1[0]!='\0')
    {
        strcpy(user.name,name1);
    }
    else{
        printf("Name can't be empty!Reenter the name\n");
        goto rename ;
    }
    printf("Enter Age\n");
    reage :
    scanf("%f",&age);
    if(validateage(age)==1)
    {
        user.age1 =age1;
    }
    else
    {
        printf("Age should be numerics\n");
        goto reage;

    }
    printf("Enter Phone Number\n");
    phno1:
    scanf("%s",phno);
    if(validatephno(phno))
    {
        strcpy(user.phoneNumber,phno);
    }
    else
    {
        printf("Phone number should consists 10 digits only\n");
        goto phno1;
    }
    printf("Enter email\n");
    email1:
    scanf("%s",email);
    if(validateemail(email)==1 && checkmail(email)==1)
    {
        strcpy(user.emaild,email);
    }
    else
    {
        //printf("Invalid email\n");
        goto email1;
    }
    printf("Enter college\n");
    college1:
        getchar();
    gets(college);
    if(college[0]!='\0')
    {
        strcpy(user.collegeName,college);
    }
    else
    {
        printf("College name can't be empty!Re-enter college name\n");
        goto college1;
    }
    printf("Enter college registration number\n");
    RN1:
    scanf("%s",RN);
    if(validateregno(RN))
    {
        user.registrationNumber;
    }
    else
    {
        //printf("Entered registration number doesn't belong to list");
        goto RN1;
    }
    printf("Enter branch\n");

    getchar();
    branch2:
    gets(branch1);
    //printf("%s",branch1);
    if(validatebranch(branch1))
    {
        //printf("\nif\n");
        strcpy(user.branch,branch1);
    }
    else
    {
        //printf("\nelse\n");
        printf("Entered branch doesn't belong to list\n");
        goto branch2;

    }

    printf("Enter Semester\n");

    int sem1;
     sem2:
    scanf("%d",&sem1);
    if(sem1>0&&sem1<=8)
    {
        user.sem = sem1;
    }
    else
    {
        printf("Semester should be less than 8\n");
        goto sem2;
    }
    printf("Enter password\n");
    pass2:
        scanf("%s",pass1);
        if(validatepass(pass1))
        {
            strcpy(user.password,pass1);

        }
        else
        {
            printf("Password must consists of atleast 2[A-Z],2[a-z],2[!@...+*]and 2[0-9] characters\n");
            goto pass2;
        }
        char pass3[50];
        printf("Confirm password\n");
        pass4:
        scanf("%s",pass3);
        if(strcmp(pass1,pass3)!=0)
        {
            printf("Passwords doesn't match\n");
            goto pass4;

        }
        printf("Enter languages known\n");
            scanf("%s",lan);
        strcpy(user.language,lan);

    printf("Enter cgpa\n");
    cgpa2:
    scanf("%f",&cgpa1);
    if(validatecgpa(cgpa1))
    {
        user.cgpa = cgpa1;

    }
    else
    {
        printf("CGPA should be less than 10 and numeric value\n");
        goto cgpa2;
    }
    //user.id=assnid(&user.id);
    FILE *fp;
    fp=fopen("user.txt" ,"a+");
    if(fp==NULL)
    {
        printf("Some error occured!!!\nPlease contact the developer\n");
        exit(0);
    }
    struct u idy;
    long int fsize=0;
    fseek(fp, 0, SEEK_END);
    fsize= ftell(fp);
    //printf(" %d ",fsize);
    if(fsize==0)
    {
       // *p=5000;
       user.id=5000;
       fclose(fp);
       //printf("%d",user.id);
    }

    else
    {
        rewind(fp);
        for(;!feof(fp);)
        {
            fread(&idy,sizeof(idy),1,fp);
            //z=
           // printf(" %d ",idy.id);
        }
        user.id=(idy.id+1);
        fclose(fp);
    }

    signup(user);
    struct u check;
    FILE *fpp;
    fpp=fopen("user.txt","r");
    while(!feof(fpp))
    {
        fread(&check,sizeof(check),1,fpp);
    }
    printf("Your signup is successfull and your user id is %d\n",check.id);
    }
    if(n==1)
        signin();

        return 0;

}
int validatebranch(char branch[50])
{
    if(strcmp(branch,"Computer Science")==0 || strcmp(branch,"Information Science")==0 || strcmp(branch,"Electronics and Communication")==0 || strcmp(branch,"Electrical")==0 || strcmp(branch,"Electronics and Instrumentation")==0)
        return 1;
        else return 0;
}
int validateregno(char rn[50])
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
int validateage(float age)
{
    int i;
    i=age;
    if(i==age)
        return 1;
    else return 0;
}
int validatecgpa(float cgpa)
{
   // int i=cgpa;
    if(cgpa<=10)
        return 1;
    else return 0;
}
int validatephno(char pn[20])
{
    if(strlen(pn)==10)
    {
        int i;
        for(i=0;i<10;i++)
        {
            if (isdigit(pn[i])==0)
            return 0;

        }
        return 1;

    }
    else return 0;
}
int validatepass(char p[50])
{
    int i;
    int cnt1=0,cnt2=0, cnt3=0,cnt4=0;
    for(i=0;i<strlen(p);i++)
    {
        if(p[i]>64 && p[i]<91)
            cnt1++;
        else if(p[i]>96 && p[i]<123)
            cnt2++;
        else if(p[i]>47 && p[i]<58)
            cnt3++;
        else
            cnt4++;
    }
   // printf("%d %d %d %d",cnt1,cnt2,cnt3,cnt4);
    if(cnt1>1 && cnt2>1 && cnt3>1 && cnt4>1)
        return 1;
    else return 0;

}
int validateemail(char a[50])
{
    int i,cntat=0,indxat,cntdt=0;
    for(i=0;i<strlen(a);i++)
    {
        if(a[i]=='@')
        {
            cntat++;
            indxat=i;
           // printf("/n AAA /n");
        }


    }
    int j;
    for(j=indxat+1;j<strlen(a);j++)
    {
        if(a[j]=='.')
            cntdt++;
            //printf("/n bbb /n");

    }
    if(cntat!=1 || cntdt<1)
    {
        printf("Invalid email\n");
        return 0;
    }
        else return 1;
}
int checkmail(char email[50])
{
    struct u t;
    FILE *chk;
    chk = fopen("user.txt" ,"a+");
    if(chk==NULL)
    {
        printf("Some error occured!!!\nPlease contact the developer\n");
        exit(0);
    }
    for(;!feof(chk);)
    {
        fread(&t,sizeof(t),1,chk);
        //printf("%s",t.emaild);
        if(strcmp(t.emaild,email)==0)
        {
            printf("Email-id already exists\n");
            fclose(chk);
            return 0;
        }
    }
    fclose(chk);
    return 1;
}
void signup(struct u s)
{
    FILE *ptr;
    ptr = fopen("user.txt" ,"a+ ");
    if(ptr==NULL)
    {
        printf("Some error occured!!!\nPlease contact the developer\n");
        exit(0);
    }
    fwrite(&s,sizeof(s),1,ptr);
    fclose(ptr);
}
void signin()
{
        printf("Enter username\n");
        char usn[50];
        USN1:
        scanf("%s",usn);
        if(strcmp(usn,"admin")==0)
        {
            char apas[50];
            printf("Enter admin password\n");
            aapas:
            scanf("%s",apas);
            if (strcmp(apas,"admin")==0)
            {
                adminui();
            }
            else{
                printf("Invalid admin password\n");
                goto aapas;
            }
        }
        else if(checkusn(usn)==0)
        {
            printf("Username doesn't exists!!!\n");
            goto USN1;
        }
}
void adminui()
{
    printf("\n\nWelcome Admin\n\n");
    adchs:
    printf("1.Add Internship\n2.Create Batch\nPress any other key to exit\nEnter your choice\n");
    int ch;
    scanf("%d",&ch);
    if(ch==1)
    {
        addint();
        goto adchs;
    }
    else if (ch==2)
    {
        addbtch();
        goto adchs;
    }
    else
    {
        printf("Exiting ....");
        exit(0);
    }
}
void addint()
{

    struct intern s;

        puts("Enter Internship name");
        getchar();
        gets(s.name);
        puts("Enter Description");
        //getchar();
        gets(s.des);
        puts("Enter requirements");
        //getchar();
        gets(s.req);
        puts("Enter branch");
        //getchar();
        gets(s.bran);
        puts("Enter semester");
        scanf("%d",&s.sem);
        puts("Enter number of students per batch");
        scanf("%d",&s.spb);
    FILE *aip;
    aip=fopen("internship.txt" ,"a+");
    if(aip==NULL)
    {
        printf("Some error occured!!!\nPlease contact the developer\n");
        exit(0);

    }
    struct intern iid;
    long int fsize=0;
    fseek(aip, 0, SEEK_END);
    fsize= ftell(aip);
    //printf(" %d ",fsize);
    if(fsize==0)
    {
       // *p=5000;
       s.id=1;
       fclose(aip);
       //printf("%d",s.id);
    }

    else
    {
        rewind(aip);
        for(;!feof(aip);)
        {
            fread(&iid,sizeof(iid),1,aip);
            //z=
           // printf(" %d ",idy.id);
        }
        s.id=(iid.id+1);
        fclose(aip);
    }

        FILE *afp;
        afp=fopen("internship.txt","a+");
        fwrite(&s,sizeof(s),1,afp);

        fclose(afp);


}
int checkusn(char usn[50])
{
    struct u s;
    FILE *pt;
    pt = fopen("user.txt" ,"a+");
    if(pt==NULL)
    {
        printf("Some error occured!!!\nPlease contact the developer\n");
        exit(0);
    }
    for(;!feof(pt);)
    {
       fread(&s,sizeof(s),1,pt);
      // { printf(" q ");
        if(strcmp(s.emaild,usn)==0||strcmp(usn,"admin")==0)
        {
            printf("Enter password\n");
            char pss[50];
            pss1:
            scanf("%s",pss);
            if(strcmp(s.password,pss)!=0)
            {
                printf("Invalid password!!!Please try again\n");
                goto pss1;
            }
            else
            {
                printf("Welcome %s please select an internship mentioned below\n",s.name);
                chkin(s.id);
                return 0;
            }

            fclose(pt);

            return 1;
        }
    }
    fclose(pt);
    return 0;
}
void chkin(int a)
{
    FILE *fi;
    struct intern is;
        fi=fopen("internship.txt","r");
        while(fread(&is,sizeof(is),1,fi)>0)
        {
            printf("%d %s\n",is.id,is.name);
        }
        fclose(fi);
    int choice;
    scanf("%d",&choice);
    chkid(a,choice);
}
void chkid(int a,int b)
{
    FILE *fui;
    struct ui si;
    fui=fopen("userinternship.txt","a+");
    if(fui==NULL)
    {
        printf("Some error occured!!!\nPlease contact the developer\n");
        exit(0);
    }
    rewind(fui);
    while(!feof(fui))
    {
        fread(&si,sizeof(si),1,fui);
        if(si.userid==a)
        {
            printf("You have a pending internship\n");
            exit(0);
        }
    }
    fclose(fui);
    FILE *fuil;
    struct ui si1;
    fuil=fopen("userinternship.txt","a+");
    if(fuil==NULL)
    {
        printf("Some error occurred !!!\nPlease contact the developer\n");
        exit(0);
    }

    struct ui idyl;
    long int fsize=0;
    fseek(fuil, 0, SEEK_END);
    fsize= ftell(fuil);
    //printf(" %d ",fsize);
    if(fsize==0)
    {
       // *p=5000;
       si1.uiid=1000;
       //fclose(fui1);
       //printf("%d",user.id);
    }

    else
    {
        rewind(fuil);
        for(;!feof(fuil);)
        {
            fread(&idyl,sizeof(idyl),1,fuil);
            //z=
           // printf(" %d ",idy.uiid);
        }
        si1.uiid=(idyl.uiid+1);
        //fclose(fui1);
    }


    //si1.uiid=a*1000+b;
    si1.inid=b;
    si1.userid=a;
    strcpy(si1.batch,"0");
    fwrite(&si1,sizeof(si1),1,fuil);
    fclose(fuil);
    printf("You have successfully registered for the internship\n");
    exit(0);
}
void usint()
{
    FILE *fuit;
    fuit=fopen("userinternship.txt","r");
    struct ui ux;
    if(fuit==NULL)
    {
        printf("Some error occurred!!!\nPlease contact the developer\n");
        exit(0);
    }
    else
    {
        while(fread(&ux,sizeof(ux),1,fuit)>0)
        {
            printf("%d %d %d %s",ux.inid,ux.userid,ux.uiid,ux.batch);
            printf("\n");
        }
    }
    fclose(fuit);
}
void addbtch()
{
    printf("Select internship \n");
    FILE *fib;
    struct intern isb;
        fib=fopen("internship.txt","r");
        while(fread(&isb,sizeof(isb),1,fib)>0)
        {
            printf("%d %s %s %d\n",isb.id,isb.name,isb.bran,isb.sem);
        }
        fclose(fib);
        int chs;
        printf("Enter your choice\n");
        scanf("%d",&chs);
        cplink(chs);
}
void cplink(int c)
{
    FILE *l;
    struct ui lis;
        l=fopen("userinternship.txt","r");
        while(fread(&lis,sizeof(lis),1,l)>0)
        {
            addnode(lis);
        }
        fclose(l);
        struct node *q=head;
        while(q!=NULL)
        {
            if(q->inidn==c)
            {
                struct uii *temp=(struct uii *)malloc(sizeof(struct uii));
                temp->link=NULL;
                temp->usid=q->useridn;
                struct uii* n=headd;
                if(n==NULL)
                {
                    headd=temp;

                }
                else
                {
                    while(n->link!=NULL)
                    {
                        n=n->link;
                    }
                    n->link=temp;
                }
            }
            q=q->link;
        }
        chiss:
        printf("Choose criteria\n1.First in first\n2.Based on branch\n3.Based on semester\n4.Finalize batch\nEnter your choice");
        int chis;
        scanf("%d",&chis);
        if(chis==1) goto chiss;
        else if(chis==2)
        {
            srtbc(c);
            goto chiss;
        }
        else if(chis==3)
        {
            srtsm(c);
            goto chiss;
        }
        else if(chis==4) dislst(c);
        else printf("Invalid choice");
        //display();
}
void addnode(struct ui lis)
{
            struct node *n;
            struct node *temp=(struct node*)malloc(sizeof(struct node));
            n=head;
            strcpy(temp->batchn,lis.batch);
            temp->inidn=lis.inid;
            temp->uiidn=lis.uiid;
            temp->useridn=lis.userid;
            temp->link=NULL;
            if(n==NULL)
            {
                head=temp;

            }
            else
            {
                while(n->link!=NULL)
                {
                    n=n->link;
                }
                n->link=temp;
            }
}
void display ( )
{
    struct node *temp =head;
	if(temp==NULL)
	{
	    printf("List is empty");
	    return;
	}
	while(temp!=NULL)
	{
	    printf("%d %s\n",temp->useridn,temp->batchn);
	    temp=temp->link;
	}

}
void srtbc(int c)
{
    FILE *bcu,*bci;
    bcu=fopen("user.txt","r");
    bci=fopen("internship.txt","r");
    struct uii *n=headd,*prev=NULL;
    struct u ubc;
    struct intern intr;
    char brch[100];
    while(fread(&intr,sizeof(intr),1,bci)>0)
    {
        if(intr.id==c)
        {
        strcpy(brch,intr.bran);
        }
    }
    if(delcntbr==0)
    {
        while(n!=NULL)
        {
        //printf("%p %d\n",prev,n->usid);
        struct uii *n1=headd1;
        int count=0;
        int count1=0;
        int count2=0;
        int count3=0;
        while(fread(&ubc,sizeof(ubc),1,bcu)>0)
        {
            if(n->usid==ubc.id && strcmp(brch,ubc.branch)==0)
            {
                if(n==headd && headd1==NULL)
                {
                    headd1=headd;
                    headd=headd->link;
                    count1++;
                    n1=headd1;
                    delcntsm++;
                }
                else if(n==headd )
                {
                    while(n1->link!=NULL)
                    {
                        n1=n1->link;
                    }
                    delcntsm++;
                    n1->link=headd;
                    headd=headd->link;
                    count2++;
                }
                else
                {
                    if(headd1==NULL)
                    {
                        headd1=n;
                        count1++;
                        delcntsm++;
                    }
                    else
                    {
                         //printf(" ddhd %d %d\n",prev->usid,n->usid);
                        while(n1->link!=NULL)
                        {
                            n1=n1->link;
                        }
                        n1->link=n;
                        prev->link=n->link;
                        count3++;

                        delcntsm++;
                        //printf("fdfv %d %d\n",prev->usid,n->usid);


                    }

                }
                count++;
            }


        }
        rewind(bcu);
        if (count==0)
        {
            prev=n;
        }
        //printf("%d %d %p\n",prev->usid,n->usid,n);
        n=n->link;
        //printf("%d %p\n",prev->usid,n);
        if(count1==1)
        headd1->link=NULL;
        if(count2==1)
            n1->link->link=NULL;
        if(count3==1)
            n1->link->link=NULL;
        }
        struct uii *n2=headd1;
        if(headd1==NULL)
            headd1=headd;
        else
        {
            while(n2->link!=NULL)
            {
                n2=n2->link;
            }
            n2->link=headd;
        }
        headd=headd1;
        headd1=NULL;
    }
    else
    {
        while(n!=NULL && delcntbr!=0)
        {
        delcntbr--;
        struct uii *n1=headd1;
        int count=0;
        int count1=0;
        int count2=0;
        while(fread(&ubc,sizeof(ubc),1,bcu)>0)
        {
            //printf("\n%d %s %d %s\n",ubc.id,ubc.branch,n->usid,brch);

            if(n->usid==ubc.id && strcmp(brch,ubc.branch)==0)
            {
                if(n==headd && headd1==NULL)
                {
                    printf("\nif\n");
                    headd1=headd;
                    headd=headd->link;
                    count1++;
                    n1=headd1;

                }
                else if(n==headd )
                {
                    while(n1->link!=NULL)
                    {
                        n1=n1->link;

                    }

                    n1->link=headd;
                    headd=headd->link;
                    count2++;

                }
                else
                {
                    prev->link=n->link;
                    if(headd1==NULL)
                    {
                        headd1=n;
                        headd1->link=NULL;

                    }
                    else
                    {
                        while(n1->link!=NULL)
                        {
                            n1=n1->link;
                        }
                        n1->link=n;
                        n1->link->link=NULL;

                    }

                }
                count++;
            }


        }
        rewind(bcu);
        if (count==0)
        {
            prev=n;
        }
        n=n->link;
        if(count1==1)
        headd1->link=NULL;
        if(count2==1)
            n1->link->link=NULL;
        }
        struct uii *n2=headd1;
        if(headd1==NULL)
            headd1=headd;
        else
        {
            while(n2->link!=NULL)
        {
            n2=n2->link;
        }
            n2->link=headd;
        }
        headd=headd1;
        headd1=NULL;
    }
}
void srtsm(int c)
{
    FILE *bcu,*bci;
    bcu=fopen("user.txt","r");
    bci=fopen("internship.txt","r");
    struct uii *n=headd,*prev=NULL;
    struct u ubc;
    struct intern intr;
    int sm;
    while(fread(&intr,sizeof(intr),1,bci)>0)
    {
        if(intr.id==c)
        {
        sm=intr.sem;
        }
    }
    if (delcntsm==0)
    {
        while(n!=NULL)
        {
        struct uii *n1=headd1;
        int count=0;
        int count1=0;
        int count2=0;
        int count3=0;
        while(fread(&ubc,sizeof(ubc),1,bcu)>0)
        {
            if(n->usid==ubc.id && ubc.sem==sm)
            {
                if(n==headd && headd1==NULL)
                {
                    headd1=headd;
                    headd=headd->link;
                    count1++;
                    n1=headd1;
                    delcntbr++;
                }
                else if(n==headd )
                {
                    while(n1->link!=NULL)
                    {
                        n1=n1->link;
                    }

                    n1->link=headd;
                    headd=headd->link;
                    count2++;
                    delcntbr++;
                }
                else
                {

                    if(headd1==NULL)
                    {
                        headd1=n;
                        count1++;
                        delcntbr++;
                    }
                    else
                    {

                        while(n1->link!=NULL)
                        {
                            n1=n1->link;
                        }
                        n1->link=n;
                        prev->link=n->link;
                        count3++;
                        delcntbr++;
                    }



                }
                count++;
            }


        }
        rewind(bcu);
        if (count==0)
        {
            prev=n;
        }
        n=n->link;
        if(count1==1)
        headd1->link=NULL;
        if(count2==1)
            n1->link->link=NULL;
            if(count3==1)
            n1->link->link=NULL;
        }
        struct uii *n2=headd1;
        if(headd1==NULL)
            headd1=headd;
        else
        {
            while(n2->link!=NULL)
            {
                n2=n2->link;
            }
            n2->link=headd;
        }
        headd=headd1;
        headd1=NULL;
    }
    else
    {
        while(n!=NULL && delcntsm!=0)
        {
        delcntsm--;
        struct uii *n1=headd1;
        int count=0;
        int count1=0;
        int count2=0;
        while(fread(&ubc,sizeof(ubc),1,bcu)>0)
        {
            if(n->usid==ubc.id && ubc.sem==sm)
            {
                if(n==headd && headd1==NULL)
                {
                    headd1=headd;
                    headd=headd->link;
                    count1++;
                    n1=headd1;

                }
                else if(n==headd )
                {
                    while(n1->link!=NULL)
                    {
                        n1=n1->link;
                    }

                    n1->link=headd;
                    headd=headd->link;
                    count2++;

                }
                else
                {
                    prev->link=n->link;
                    if(headd1==NULL)
                    {
                        headd1=n;
                        count1++;

                    }
                    else
                    {
                        while(n1->link!=NULL)
                        {
                            n1=n1->link;
                        }
                        n1->link=n;
                        n1->link->link=NULL;

                    }

                }
                count++;
            }


        }
        rewind(bcu);
        if (count==0)
        {
            prev=n;
        }
        n=n->link;
        if(count1==1)
        headd1->link=NULL;
        if(count2==1)
            n1->link->link=NULL;
        }
        struct uii *n2=headd1;
        if(headd1==NULL)
            headd1=headd;
        else
        {
            while(n2->link!=NULL)
            {
                n2=n2->link;
            }
            n2->link=headd;
        }
        headd=headd1;
        headd1=NULL;
    }

}
void dislst(int c)
{
    FILE *bci;
    int cntspb=0,cntbinc=1;
    //bcu=fopen("user.txt","r");
    bci=fopen("internship.txt","r");
    //struct uii *n=headd,*prev=NULL;
    //struct u ubc;
    struct intern intra;
    int btch;
    while(fread(&intra,sizeof(intra),1,bci)>0)
    {
        if(intra.id==c)
        {
        btch=intra.spb;
        }
    }
    struct uii *nn=headd;
    while(nn!=NULL)
    {
        struct node *nn1=head;
        //cntspb=0;
        while(nn1!=NULL)
        {

            if (nn->usid==nn1->useridn)
            {
                char btch1[50];
                nn1->batchn[0]=64+c;
                if(cntbinc>0 && cntbinc<10)
                {
                    nn1->batchn[1]=48+cntbinc;
                    nn1->batchn[2]='\0';
                }
                else if(cntbinc>9 && cntbinc<100)
                {
                    nn1->batchn[1]=48+cntbinc/10;
                    nn1->batchn[2]=48+cntbinc%10;
                    nn1->batchn[3]='\0';
                }
                else if(cntbinc>99 && cntbinc<1000)
                {
                    nn1->batchn[1]=48+cntbinc/100;
                    nn1->batchn[2]=48+cntbinc/10;
                    nn1->batchn[3]=48+cntbinc%10;
                    nn1->batchn[4]='\0';
                }
                cntspb++;
            }
            nn1=nn1->link;
        }
        if(cntspb==btch)
        {
            cntbinc++;
            cntspb=0;
        }
        nn=nn->link;
    }
    FILE *fin;
    fin=fopen("userinternship1.txt","w+");
    struct ui fin1;
    struct node *fin2=head;
    while(fin2!=NULL)
    {
        fin1.inid=fin2->inidn;
        fin1.uiid=fin2->uiidn;
        fin1.userid=fin2->useridn;
        strcpy(fin1.batch,fin2->batchn);
        fwrite(&fin1,sizeof(fin1),1,fin);
        fin2=fin2->link;
    }
    rewind(fin);
    while(fread(&fin1,sizeof(fin1),1,fin)>0)
    {
        printf("Batch %s User-id %d Inte.-id %d Userinte.-id %d\n",fin1.batch,fin1.userid,fin1.inid,fin1.uiid);
    }
    display();
}





