#include<stdio.h>
#include<string.h>
#include<math.h>
#include<conio.h>
#define SIZE 40
struct accommodation
{ 
	char firstname[50]; 
	char lastname[50]; 
	char accommodation_type [20];
	int idtype; 
	char address[100]; 
	int blockind;
	struct idnum
	{ 
		char aadhaar[15]; 
		char passport[15]; 
		char empcode [15];
	}id; 	
};

struct block
{
	int t1[10];
	int t2[10];
	int t3[10];
	int t4[10];
	
};



void InsertRecord(struct accommodation B[],int n,struct block t[]);
void RemoveDuplicates(struct accommodation B[],int n,int index[],struct block t[]);
void Initialise(struct accommodation B[],int n);
void InitialiseBlock(struct block t[]);
void PrintRecords(struct accommodation B[],int n);
void AlphaSort(struct accommodation B[],int n,int index[]);
void printSortedRecords(struct accommodation B[],int n,int index[]);
void search(struct accommodation B[],int n,int index[]);
void deleteRecord(struct accommodation B[],int idtype, char idnum[],struct block t[]);
void updateRecord(struct accommodation B[]);
void specialRequestAllocation(struct accommodation B[],struct block t[]);

int main()
{
	int i,option,idty,num;
	int quit=0;
	int index[SIZE];
	char idnumber[15];
	idnumber[0]='\0';
	struct accommodation B[SIZE];
	struct block t[1];
	Initialise(B,SIZE);
	InitialiseBlock(t);
	printf("WELCOME TO VNIT ACCOMMODATION CENTRE\n");
	while(quit==0)
	{
		printf("Choose the following by pressing corresponding value\n");
		printf("Insert Record - 0 | Remove Duplicates - 1 | Print Records - 2 | Print Sorted Records - 3 | Search - 4\n" );
		printf("Delete Record - 5 | Update Record - 6 | Special Request Allocation - 7 | Quit - 8\n");
		scanf("%d",&option);
		idnumber[0]='\0';
		switch(option)
		{
			case 0:
				{
					printf("How many records to Insert?");
					scanf("%d",&num);
					for(i=0;i<num;i++)
					{
						InsertRecord(B,SIZE,t);
					}
				}
				break;
			case 1:
				{
					RemoveDuplicates(B,SIZE,index,t);
					AlphaSort(B,SIZE,index);
					printf("Duplicates Removed");
				}
				break;
			case 2:
				{
					PrintRecords(B,SIZE);
				}
				break;
			case 3:
				{
					printSortedRecords(B,SIZE,index);
				}
				break;
			case 4:
				{
					search(B,SIZE,index);
				}
				break;
			case 5:
				{
					printf("Enter ID type 0-2");
					scanf("%d",&idty);
					printf("Enter ID number");
					scanf("%s",&idnumber);
					deleteRecord(B,idty,idnumber,t);
					AlphaSort(B,SIZE,index);
				}
				break;
			case 6:
				{
					updateRecord(B);
					AlphaSort(B,SIZE,index);
				}
				break;
			case 7:
				{
					specialRequestAllocation(B,t);
				}
				break;
			case 8:
				{
					quit=1;
					printf("Thank you");
				}
				break;
			default:
				{
					printf("Invalid choice");
				}
		}
	}
	return 0;
	
}

void Initialise(struct accommodation B[],int n)
{
	int i=0;
	for(i=0;i<n;i++)
	{
		B[i].firstname[0]='\0';
		B[i].lastname[0]='\0';
		B[i].accommodation_type[0]='\0';
		B[i].idtype=-1;
		B[i].id.aadhaar[0]='\0';
		B[i].id.passport[0]='\0';
		B[i].id.empcode[0]='\0';
		B[i].address[0]='\0';
		B[i].blockind=-1;
		
	}
}

void InitialiseBlock(struct block t[])
{
	int i;
	for(i=0;i<10;i++)
	{
		t[0].t1[i]=0;
		t[0].t2[i]=0;
		t[0].t3[i]=0;
		t[0].t4[i]=0;
	}
}

void InsertRecord(struct accommodation B[],int n,struct block t[])
{
	int i=0;
	int found=0;
	int choice;
	int avail=0;
	int k;
	char t1[7]={'t','y','p','e','-','1','\0'};
	char t2[7]={'t','y','p','e','-','2','\0'};
	char t3[7]={'t','y','p','e','-','3','\0'};
	char t4[7]={'t','y','p','e','-','4','\0'};
	printf("INSERT RECORD\n");
	printf("Enter the type of accommodation\nEnter number accordingly\n");
	printf("Type-1 - 1 |  Type-2 - 2 | Type-3 - 3 | Type-4 - 4\n");
	scanf("%d",&choice);
	
	if(choice==1)
	{
		for(k=0;k<10 && avail==0;k++)
		{
			if(t[0].t1[k]==0)
			{
				avail=1;
				t[0].t1[k]=1;
				k--;
			}
		}
	}
	else if(choice==2)
	{
		for(k=0;k<10 && avail==0;k++)
		{
			if(t[0].t2[k]==0)
			{
				avail=1;
				t[0].t2[k]=1;
				k--;
			}
		}
	}
	else if(choice==3)
	{
		for(k=0;k<10 && avail==0;k++)
		{
			if(t[0].t3[k]==0)
			{
				avail=1;
				t[0].t3[k]=1;
				k--;
			}
		}
	}
	else if(choice==4)
	{
		for(k=0;k<10 && avail==0;k++)
		{
			if(t[0].t4[k]==0)
			{
				avail=1;
				t[0].t4[k]=1;
				k--;
			}
		}
	}
	
	
	if(k<10)
	{
		for(i=0;i<n && found==0;i++)
		{
			if(B[i].firstname[0]=='\0')
			{
				found=1;
				B[i].blockind=k;
				printf("Enter first name\n");
				scanf("%s",&B[i].firstname);
				printf("Enter last name\n");
				scanf("%s",&B[i].lastname);
				printf("Accommodation type-\n");
				if(choice==1)
				{
					strcpy(B[i].accommodation_type,t1);
					printf("%s\n",B[i].accommodation_type);
				}
				else if(choice==2)
				{
					strcpy(B[i].accommodation_type,t2);
					printf("%s\n",B[i].accommodation_type);
				}
				else if(choice==3)
				{
					strcpy(B[i].accommodation_type,t3);
					printf("%s\n",B[i].accommodation_type);
				}
				else if(choice==4)
				{
					strcpy(B[i].accommodation_type,t4);
					printf("%s\n",B[i].accommodation_type);
				}
				//printf("Enter ccommodation type\n");
				//scanf("%s",&B[i].accommodation_type);
				printf("Enter ID type\n");
				scanf("%d",&B[i].idtype);
				if(B[i].idtype==0)
				{
					printf("Enter AADHAAR NO.\n");
					scanf("%s",&B[i].id.aadhaar);
				}
				else if(B[i].idtype==1)
				{
					printf("Enter PASSPORT NO.\n");
					scanf("%s",&B[i].id.passport);
				}
				else
				{
					printf("Enter EMPLOYEE CODE.\n");
					scanf("%s",&B[i].id.empcode);
				}
				fflush(stdin);
				printf("Enter address\n");
				gets(B[i].address);
			}		
		}
	}
	else
	{
		printf("Blocks for Type-%d are full",choice);
	}
	
}


void RemoveDuplicates(struct accommodation B[],int n,int index[],struct block t[])
{
	int i,j,k;
	char t1[7]={'t','y','p','e','-','1','\0'};
	char t2[7]={'t','y','p','e','-','2','\0'};
	char t3[7]={'t','y','p','e','-','3','\0'};
	char t4[7]={'t','y','p','e','-','4','\0'};
	for(i = 0; i < n; i++)
    {
    	if(B[i].idtype==0 || B[i].idtype==1 || B[i].idtype==2)
    	{
	        for(j = i+1; j < n; j++)
	        {
	        	if(B[j].idtype==0 || B[j].idtype==1 || B[j].idtype==2)
	        	{
		        	if(B[i].idtype==0 && B[j].idtype==0)
		        	{
		            	if(strcmp(B[j].id.aadhaar,B[i].id.aadhaar) == 0)
		            	{
		                	B[j].firstname[0]='\0';
							B[j].lastname[0]='\0';
							if(strcmp(B[j].accommodation_type,t1)==0)
							{
								t[0].t1[B[j].blockind]=0;
							}
							else if(strcmp(B[j].accommodation_type,t2)==0)
							{
								t[0].t2[B[j].blockind]=0;
							}
							else if(strcmp(B[j].accommodation_type,t3)==0)
							{
								t[0].t3[B[j].blockind]=0;
							}
							else if(strcmp(B[j].accommodation_type,t4)==0)
							{
								t[0].t4[B[j].blockind]=0;
							}
							B[j].accommodation_type[0]='\0';
							B[j].idtype=-1;
							B[j].id.aadhaar[0]='\0';
							B[j].id.passport[0]='\0';
							B[j].id.empcode[0]='\0';
							B[j].address[0]='\0';
							B[j].blockind=-1;
		            	}
		        	}
		        	else if(B[i].idtype==1 && B[j].idtype==1)
		        	{
		            	if(strcmp(B[j].id.passport,B[i].id.passport)==0)
		            	{
		                	B[j].firstname[0]='\0';
							B[j].lastname[0]='\0';
							if(strcmp(B[j].accommodation_type,t1)==0)
							{
								t[0].t1[B[j].blockind]=0;
							}
							else if(strcmp(B[j].accommodation_type,t2)==0)
							{
								t[0].t2[B[j].blockind]=0;
							}
							else if(strcmp(B[j].accommodation_type,t3)==0)
							{
								t[0].t3[B[j].blockind]=0;
							}
							else if(strcmp(B[j].accommodation_type,t4)==0)
							{
								t[0].t4[B[j].blockind]=0;
							}
							B[j].accommodation_type[0]='\0';
							B[j].idtype=-1;
							B[j].id.aadhaar[0]='\0';
							B[j].id.passport[0]='\0';
							B[j].id.empcode[0]='\0';
							B[j].address[0]='\0';
							B[j].blockind=-1;
		            	}
		        	}
		        	else if(B[i].idtype==2 && B[j].idtype==2)
		        	{
		            	if(strcmp(B[j].id.empcode,B[i].id.empcode)==0)
		            	{
		                	B[j].firstname[0]='\0';
							B[j].lastname[0]='\0';
							if(strcmp(B[j].accommodation_type,t1)==0)
							{
								t[0].t1[B[j].blockind]=0;
							}
							else if(strcmp(B[j].accommodation_type,t2)==0)
							{
								t[0].t2[B[j].blockind]=0;
							}
							else if(strcmp(B[j].accommodation_type,t3)==0)
							{
								t[0].t3[B[j].blockind]=0;
							}
							else if(strcmp(B[j].accommodation_type,t4)==0)
							{
								t[0].t4[B[j].blockind]=0;
							}
							B[j].accommodation_type[0]='\0';
							B[j].idtype=-1;
							B[j].id.aadhaar[0]='\0';
							B[j].id.passport[0]='\0';
							B[j].id.empcode[0]='\0';
							B[j].address[0]='\0';
							B[j].blockind=-1;
		            	}
		        	}
		    	}
	        }
		}
    }
}


void PrintRecords(struct accommodation B[],int n)
{
	int i;
	for(i=0; i<n ;i++)
	{
		if(B[i].idtype==1)
		{
			printf("Firstname- %s\n",B[i].firstname);
			printf("Lastname- %s\n",B[i].lastname);
			printf("Accommodation type- %s\n",B[i].accommodation_type);
			printf("ID type- %d\n",B[i].idtype);
			printf("Block number- %d\n",B[i].blockind);
			printf("PASSPORT- %s\n",B[i].id.passport);
			printf("Address- %s\n\n",B[i].address);
		}
	}
	for(i=0; i<n ;i++)
	{
		if(B[i].idtype==0)
		{
			printf("Firstname- %s\n",B[i].firstname);
			printf("Lastname- %s\n",B[i].lastname);
			printf("Accommodation type- %s\n",B[i].accommodation_type);
			printf("ID type- %d\n",B[i].idtype);
			printf("Block number- %d\n",B[i].blockind);
			printf("AADHAAR- %s\n",B[i].id.aadhaar);
			printf("Address- %s\n\n",B[i].address);
		}
	}
	for(i=0; i<n ;i++)
	{
		if(B[i].idtype==2)
		{
			printf("Firstname- %s\n",B[i].firstname);
			printf("Lastname- %s\n",B[i].lastname);
			printf("Accommodation type- %s\n",B[i].accommodation_type);
			printf("ID type- %d\n",B[i].idtype);
			printf("Block number- %d\n",B[i].blockind);
			printf("EMPCODE- %s\n",B[i].id.empcode);
			printf("Address- %s\n\n",B[i].address);
		}
	}
}

void AlphaSort(struct accommodation B[],int n,int index[]) 
{  
    int i, j, min,tmp; 
   
    for (i=0; i<n; i++) 
    {
    	index[i] = i; 
	}
         
    for (i=0; i<n-1; i++)     
    { 
    	if(B[index[i]].idtype!=-1)
	    {
			min = i; 
			tmp=-1;
	        for (j=i+1; j<n; j++) 
	        {  
	            if ((strcmp(B[index[min]].firstname,B[index[j]].firstname) > 0))
	            {
	            	min = j; 
				}
				else if(strcmp(B[index[min]].firstname,B[index[j]].firstname)== 0)
				{
					if (strcmp(B[index[min]].lastname,B[index[j]].lastname) > 0)
					{
						min = j;
					}
					else if(strcmp(B[index[min]].lastname,B[index[j]].lastname) == 0)
					{
						tmp = index[j];	
					}
				}
	        } 
	        if (min != i) 
	        { 
	            tmp = index[min]; 
	            index[min] = index[i]; 
	            index[i] = tmp; 
	        } 
	        else if(min == i && tmp != -1)
	        {
	        	index[j] = index[i+1];
				index[i+1]=tmp;
			}
		}
    } 
}

void printSortedRecords(struct accommodation B[],int n,int index[])
{
	AlphaSort(B,SIZE,index);
	int i;
	for(i=0;i<n;i++)
	{
		if(B[index[i]].idtype!=-1)
		{
			printf("%s %s\n",B[index[i]].firstname,B[index[i]].lastname);
		}
	}
}

void search(struct accommodation B[],int n,int index[])
{
	char fname[50];
	fname[0]='\0';
	int c=-1;
	int i,begin,end;
	int low,mid,high,found;
	i=0;
	char check[50];
	check[0]='\0';
	int find;
	
	printf("Enter firstname to search\n");
	scanf("%s",&fname);
	
	while(B[index[i]].firstname[0] == '\0')
	{
		i++;
	}
	low=i;
	high=n-1;
	found=0;
	while((low<=high) && (found==0))
	{
		mid=(low+high)/2;
		strcpy(check,B[index[mid]].firstname);
		if(strcmp(check,fname) == 0)
		{
			c=mid;
			found=1;
		}
		else if(strcmp(fname,check) > 0)
		{
			low=mid+1;
		}
		else
		{
			high=mid-1;
		}
	}
	i=mid-1;
	strcpy(check,B[index[i]].firstname);
	find=0;
	while(i>=0 && find==0)
	{
		if(strcmp(check,fname) == 0)
		{
			i--;
			if(i>=0)
			{
				strcpy(check,B[index[i]].firstname);
			}
		}
		else
		{
			find=1;
		}
	}
	begin=i+1;
	
	find=0;
	i=mid+1;
	strcpy(check,B[index[i]].firstname);
	while(i<n && find==0)
	{
		if(strcmp(check,fname) == 0)
		{
			i++;
			if(i<n)
			{
				strcpy(check,B[index[i]].firstname);
			}
		}
		else
		{
			find=1;
		}
		
	}
	end=i-1;
	
	if(c!=1)
	{
		for(i=begin;i<=end;i++)
		{
			printf("Firstname- %s\n",B[index[i]].firstname);
			printf("Lastname- %s\n",B[index[i]].lastname);
			printf("Accommodation type- %s\n",B[index[i]].accommodation_type);
			printf("ID type- %d\n",B[index[i]].idtype);
			if(B[index[i]].idtype == 0)
			{
				printf("AADHAAR- %s\n",B[index[i]].id.aadhaar);
			}
			else if(B[index[i]].idtype == 1)
			{
				printf("PASSPORT- %s\n",B[index[i]].id.passport);
			}
			else if(B[index[i]].idtype == 2)
			{
				printf("EMPCODE- %s\n",B[index[i]].id.empcode);
			}
			
			printf("Address- %s\n",B[index[i]].address);
		}
	}
		
}


void deleteRecord(struct accommodation B[],int idtype, char idnum[],struct block t[])
{
	int i;
	char t1[7]={'t','y','p','e','-','1','\0'};
	char t2[7]={'t','y','p','e','-','2','\0'};
	char t3[7]={'t','y','p','e','-','3','\0'};
	char t4[7]={'t','y','p','e','-','4','\0'};
	for(i=0;i<SIZE;i++)
	{
		if(idtype==0)
		{
			if(B[i].idtype==idtype)
			{
				if(strcmp(B[i].id.aadhaar,idnum)==0)
				{
					B[i].firstname[0]='\0';
					B[i].lastname[0]='\0';
					if(strcmp(B[i].accommodation_type,t1)==0)
					{
						t[0].t1[B[i].blockind]=0;
					}
					else if(strcmp(B[i].accommodation_type,t2)==0)
					{
						t[0].t2[B[i].blockind]=0;
					}
					else if(strcmp(B[i].accommodation_type,t3)==0)
					{
						t[0].t3[B[i].blockind]=0;
					}
					else if(strcmp(B[i].accommodation_type,t4)==0)
					{
						t[0].t4[B[i].blockind]=0;
					}
					B[i].accommodation_type[0]='\0';
					B[i].idtype=-1;
					B[i].id.aadhaar[0]='\0';
					B[i].id.passport[0]='\0';
					B[i].id.empcode[0]='\0';
					B[i].address[0]='\0';
					B[i].blockind=-1;
				}
			}
		}
		else if(idtype==1)
		{
			if(B[i].idtype==idtype)
			{
				if(strcmp(B[i].id.passport,idnum)==0)
				{
					B[i].firstname[0]='\0';
					B[i].lastname[0]='\0';
					if(strcmp(B[i].accommodation_type,t1)==0)
					{
						t[0].t1[B[i].blockind]=0;
					}
					else if(strcmp(B[i].accommodation_type,t2)==0)
					{
						t[0].t2[B[i].blockind]=0;
					}
					else if(strcmp(B[i].accommodation_type,t3)==0)
					{
						t[0].t3[B[i].blockind]=0;
					}
					else if(strcmp(B[i].accommodation_type,t4)==0)
					{
						t[0].t4[B[i].blockind]=0;
					}
					B[i].accommodation_type[0]='\0';
					B[i].idtype=-1;
					B[i].id.aadhaar[0]='\0';
					B[i].id.passport[0]='\0';
					B[i].id.empcode[0]='\0';
					B[i].address[0]='\0';
					B[i].blockind=-1;
				}
			}
		}
		else if(idtype==2)
		{
			if(B[i].idtype==idtype)
			{
				if(strcmp(B[i].id.aadhaar,idnum)==0)
				{
					B[i].firstname[0]='\0';
					B[i].lastname[0]='\0';
					if(strcmp(B[i].accommodation_type,t1)==0)
					{
						t[0].t1[B[i].blockind]=0;
					}
					else if(strcmp(B[i].accommodation_type,t2)==0)
					{
						t[0].t2[B[i].blockind]=0;
					}
					else if(strcmp(B[i].accommodation_type,t3)==0)
					{
						t[0].t3[B[i].blockind]=0;
					}
					else if(strcmp(B[i].accommodation_type,t4)==0)
					{
						t[0].t4[B[i].blockind]=0;
					}
					B[i].accommodation_type[0]='\0';
					B[i].idtype=-1;
					B[i].id.aadhaar[0]='\0';
					B[i].id.passport[0]='\0';
					B[i].id.empcode[0]='\0';
					B[i].address[0]='\0';
					B[i].blockind=-1;
				}
			}
		}
	}
}


void updateRecord(struct accommodation B[])
{
	char fname[50];
	char lname[50];
	char acctype[20];
	int idtype;
	char idnum[15];
	char aadhaar[15];
	char passport[15];
	char empcode[15];
	char address[50];
	int found,i,find,choice;
	
	
	printf("Enter idtype\n");
	scanf("%d",&idtype);
	printf("Enter idnum\n");
	scanf("%s",&idnum);
	
	for(i=0;i<SIZE && !found;i++)
	{
		if(idtype==0)
		{
			if(B[i].idtype==idtype)
			{
				if(strcmp(B[i].id.aadhaar,idnum)==0)
				{
					found=1;
					find=i;
				}
			}
		}
		else if(idtype==1)
		{
			if(B[i].idtype==idtype)
			{
				if(strcmp(B[i].id.passport,idnum)==0)
				{
					found=1;
					find=i;
				}
			}
		}
		if(idtype==2)
		{
			if(B[i].idtype==idtype)
			{
				if(strcmp(B[i].id.aadhaar,idnum)==0)
				{
					found=1;
					find=i;
				}
			}
		}
	}
	
	printf("press the follwing number to update accordingly\n");
	printf("firstname-0 lastname-1 accommodation type-2 idtype-3 idnum-4 address-5 \n");
	scanf("%d",&choice);
	
	switch(choice)
	{
		case 0:
			{
				printf("Enter firstname to update\n");
				scanf("%s",&fname);
				strcpy(B[find].firstname,fname);
			}
			break;
		case 1:
			{
				printf("Enter lastname to update\n");
				scanf("%s",&lname);
				strcpy(B[find].lastname,lname);
			}
			break;
		case 2:
			{
				//printf("Enter accommodation type to update");
				//scanf("%s",&acctype);
				//strcpy(B[find].accommodation_type,acctype);
				printf("Accommodation type can be requested to change in main menu\n");
			}
			break;
		case 3:
			{
				printf("Enter idtype to update\n");
				scanf("%d",&idtype);
				B[find].idtype=idtype;
			}
			break;
		case 4:
			{
				if(idtype==0)
				{
					printf("Enter AADHAAR to update\n");
					scanf("%s",&aadhaar);
					strcpy(B[find].id.aadhaar,aadhaar);
				}
				else if(idtype==1)
				{
					printf("Enter PASSPORT to update\n");
					scanf("%s",&passport);
					strcpy(B[find].id.passport,passport);
				}
				else if(idtype==2)
				{
					printf("Enter EMPCODE to update\n");
					scanf("%s",&empcode);
					strcpy(B[find].id.empcode,empcode);
				}
			}
			break;
		case 5:
			{
				printf("Enter address to update\n");
				scanf("%d",&address);
				strcpy(B[find].address,address);
			}
			break;
		default:
			{
				printf("INVALID CHOICE\n");
			}
			break;
			
	}
	
}

void specialRequestAllocation(struct accommodation B[],struct block t[])
{
	int i,id,k,choice,flag,find;
	int found=0;
	char idnumber[15];
	idnumber[0]='\0';
	char t1[7]={'t','y','p','e','-','1','\0'};
	char t2[7]={'t','y','p','e','-','2','\0'};
	char t3[7]={'t','y','p','e','-','3','\0'};
	char t4[7]={'t','y','p','e','-','4','\0'};
	printf("SPECIAL REQUEST ALLOCATION\n");
	printf("please enter your ID type\n");
	scanf("%d",&id);
	printf("please enter ID number\n");
	scanf("%s",idnumber);
	
	for(i=0;(i<SIZE && found==0);i++)
	{
		if(B[i].idtype==0 && id==0)
		{
			if(strcmp(B[i].id.aadhaar,idnumber)==0)
			{
				found=1;
				find=i;
			}
		}
		else if(B[i].idtype==1 && id==1)
		{
			if(strcmp(B[i].id.passport,idnumber)==0)
			{
				found=1;
				find=i;
			}
		}
		else if(B[i].idtype==2 && id==2)
		{
			if(strcmp(B[i].id.empcode,idnumber)==0)
			{
				found=1;
				find=i;
			}
		}
	}
	if(found==1)
	{
		printf("Enter the type of accommodation to check for\nOr chose same type to change the block\nEnter number accordingly\n");
		printf("Type-1 - 1 |  Type-2 - 2 | Type-3 - 3 | Type-4 - 4\n");
		scanf("%d",&choice);
		
		flag=0;
		if(choice==1)
		{
			for(k=0;k<10 && flag==0;k++)
			{
				if(t[0].t1[k]==0)
				{
					flag=1;
					k--;
				}
			}
		}
		else if(choice==2)
		{
			for(k=0;k<10 && flag==0;k++)
			{
				if(t[0].t2[k]==0)
				{
					flag=1;
					k--;
				}
			}
		}
		else if(choice==3)
		{
			for(k=0;k<10 && flag==0;k++)
			{
				if(t[0].t3[k]==0)
				{
					flag=1;
					k--;
				}
			}
		}
		else if(choice==4)
		{
			for(k=0;k<10 && flag==0;k++)
			{
				if(t[0].t4[k]==0)
				{
					flag=1;
					k--;
				}
			}
		}
		else
		{
			printf("Invalid choice");	
		}
		
		
		if(flag==1)
		{
			printf("Block found\nNew allocation in type- %d block- %d\n",choice,k);
			if(strcmp(B[find].accommodation_type,t1)==0)
			{
				t[0].t1[B[find].blockind]=0;
				B[find].blockind=k;
			}
			else if(strcmp(B[find].accommodation_type,t2)==0)
			{
				t[0].t2[B[find].blockind]=0;
				B[find].blockind=k;
			}
			else if(strcmp(B[find].accommodation_type,t3)==0)
			{
				t[0].t3[B[find].blockind]=0;
				B[find].blockind=k;
			}
			else if(strcmp(B[find].accommodation_type,t4)==0)
			{
				t[0].t4[B[find].blockind]=0;
				B[find].blockind=k;
			}
			
			
			if(choice==1)
			{
				strcpy(B[find].accommodation_type,t1);
			}
			else if(choice==2)
			{
				strcpy(B[find].accommodation_type,t2);
			}
			if(choice==3)
			{
				strcpy(B[find].accommodation_type,t3);
			}
			if(choice==4)
			{
				strcpy(B[find].accommodation_type,t4);
			}
		}
	}
	else
	{
		printf("ID not found");
	}
}





