#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**************************************************
//  PersonEmployee
//
// date: 28.10.2019
// name: Yahya Guezide
// Simple Example to showcase polymorphsm in c
//
***************************************************/

typedef struct _vfunctions{
	void (*Print)(void*);
	void (*SetName)(void*, char*);
	char* (*GetName)(void*);
	void (*Free)(void*);
}vFunctions;

typedef struct _person{
	vFunctions functions;
	char *name;
}Person;

typedef struct _employee{
	Person *person;
	int employeeIndex;
	void (*SetEmIndex)(void*, int);
	int (*GetEmIndex)(void*);
}Employee;


//####### Person Functions ########
void PrintPerson( Person *p ){
	printf( "Person:\t%s\n", p->name);
}

void SetNamePerson( Person *p, char *name ){
	if( p->name != NULL )
		free( p->name);

	p->name = (char*)malloc(strlen(name)+1);
	strncpy(p->name, name, strlen(name)+1);
}

char* GetNamePerson( Person *p ){
	return p->name;
}

void FreePerson( Person *p ){
	if( p != NULL ){
		free(p->name);
		p->name = NULL;
		free(p);
	}
}

//##########

//########## Employee Functions ########
void PrintEmployee( Employee *em ){
	printf( "Employee:\t%d\t%s\n", em->employeeIndex, em->person->name);
}

void SetNameEmployee( Employee *em, char *name ){
	SetNamePerson( em->person, name );
}

void GetNameEmployee( Employee *em ){
	GetNamePerson( em->person );
}

void SetIndex( Employee *em, int i ){
	em->employeeIndex = i;
}

int GetIndex( Employee *em ){
	return em->employeeIndex;
}

void FreeEmployee( Employee *em ){
	if( em != NULL ){
		FreePerson(em->person);
		em->person = NULL;
		free(em);
	}
}
//############

Person* GetPersonInstance(){
	Person *p = (Person*)malloc(sizeof(Person));
	p->name = NULL;

	p->functions.Print = PrintPerson;
	p->functions.SetName = SetNamePerson;
	p->functions.GetName = GetNamePerson;
	p->functions.Free = FreePerson;
	return p;
}

Employee *GetEmployeeInstance( int i ){
	Employee *em = (Employee*)malloc(sizeof(Employee));
	em->employeeIndex = i;

	em->SetEmIndex = SetIndex;
	em->GetEmIndex = GetIndex;

	em->person = (Person*)malloc(sizeof(Person));
	em->person->name = NULL;

	em->person->functions.Print = PrintEmployee;
	em->person->functions.SetName = SetNameEmployee;
	em->person->functions.GetName = GetNameEmployee;
	em->person->functions.Free = FreeEmployee;
	return em;
}


int main( int argc, char **argv ){
	Person *p = GetPersonInstance();
	Employee *em = GetEmployeeInstance(0);

	p->functions.SetName(p, "Steve");
	p->functions.Print(p);

	em->person->functions.SetName(em, "Bob");
	em->person->functions.Print(em);

	em->SetEmIndex(em, 1);
	em->person->functions.Print(em);

	p->functions.Free(p);
	em->person->functions.Free(em);

    return 0;
}

