
SQL*Plus: Release 10.2.0.1.0 - Production on Mon Dec 13 13:19:31 2021

Copyright (c) 1982, 2005, Oracle.  All rights reserved.

SQL> conn
Enter user-name: system
Enter password:
ERROR:
ORA-01017: invalid username/password; logon denied


SQL> conn
Enter user-name: system
Enter password:
ERROR:
ORA-01017: invalid username/password; logon denied


SQL> connect system
Enter password:
ERROR:
ORA-01017: invalid username/password; logon denied


SQL> connect system
Enter password:
Connected.
SQL> create table liabrary (
  2  dept_id number(6),
  3  dept_name varchar(20)
  4  no_of_books_count number(6),
  5  no_of_students number(6));
no_of_books_count number(6),
*
ERROR at line 4:
ORA-00907: missing right parenthesis


SQL> create table liabrary (
  2  dept_id number(6),
  3  dept_name varchar(20),
  4  no_of_books_count number(6),
  5  no_of_student number(6));

Table created.

SQL> crete table stud_department(
SP2-0734: unknown command beginning "crete tabl..." - rest of line ignored.
SQL> create table stud_department (
  2  stud_id number(6),
  3  dept_id number(6));

Table created.

SQL> desc liabrary;
 Name                                      Null?    Type
 ----------------------------------------- -------- ----------------------------

 DEPT_ID                                            NUMBER(6)
 DEPT_NAME                                          VARCHAR2(20)
 NO_OF_BOOKS_COUNT                                  NUMBER(6)
 NO_OF_STUDENT                                      NUMBER(6)

SQL> desc stud_department;
 Name                                      Null?    Type
 ----------------------------------------- -------- ----------------------------

 STUD_ID                                            NUMBER(6)
 DEPT_ID                                            NUMBER(6)

SQL> insert into liabrary values (&dept_id,'&dept_name', &no_of_books_count,&no_
of_student);
Enter value for dept_id: 100
Enter value for dept_name: computer
Enter value for no_of_books_count: 500
Enter value for no_of_student: 180
old   1: insert into liabrary values (&dept_id,'&dept_name', &no_of_books_count,
&no_of_student)
new   1: insert into liabrary values (100,'computer', 500,180)

1 row created.

SQL> /
Enter value for dept_id: 101
Enter value for dept_name: mechanical
Enter value for no_of_books_count: 450
Enter value for no_of_student: 120
old   1: insert into liabrary values (&dept_id,'&dept_name', &no_of_books_count,
&no_of_student)
new   1: insert into liabrary values (101,'mechanical', 450,120)

1 row created.

SQL> /
Enter value for dept_id: 102
Enter value for dept_name: electrical
Enter value for no_of_books_count: 200
Enter value for no_of_student: 90
old   1: insert into liabrary values (&dept_id,'&dept_name', &no_of_books_count,
&no_of_student)
new   1: insert into liabrary values (102,'electrical', 200,90)

1 row created.

SQL> /
Enter value for dept_id: 103
Enter value for dept_name: civil
Enter value for no_of_books_count: 300
Enter value for no_of_student: 50
old   1: insert into liabrary values (&dept_id,'&dept_name', &no_of_books_count,
&no_of_student)
new   1: insert into liabrary values (103,'civil', 300,50)

1 row created.

SQL> desc liabrary;
 Name                                      Null?    Type
 ----------------------------------------- -------- ----------------------------

 DEPT_ID                                            NUMBER(6)
 DEPT_NAME                                          VARCHAR2(20)
 NO_OF_BOOKS_COUNT                                  NUMBER(6)
 NO_OF_STUDENT                                      NUMBER(6)

SQL> select * from liabrary;

   DEPT_ID DEPT_NAME            NO_OF_BOOKS_COUNT NO_OF_STUDENT
---------- -------------------- ----------------- -------------
       100 computer                           500           180
       101 mechanical                         450           120
       102 electrical                         200            90
       103 civil                              300            50

SQL> insert into stud_department values(&stud_is,&dept_id);
Enter value for stud_is: 201
Enter value for dept_id: 100
old   1: insert into stud_department values(&stud_is,&dept_id)
new   1: insert into stud_department values(201,100)

1 row created.

SQL> /
Enter value for stud_is: 202
Enter value for dept_id: 100
old   1: insert into stud_department values(&stud_is,&dept_id)
new   1: insert into stud_department values(202,100)

1 row created.

SQL> /
Enter value for stud_is: 203
Enter value for dept_id: 101
old   1: insert into stud_department values(&stud_is,&dept_id)
new   1: insert into stud_department values(203,101)

1 row created.

SQL> /
Enter value for stud_is:
Enter value for dept_id: 55
old   1: insert into stud_department values(&stud_is,&dept_id)
new   1: insert into stud_department values(,55)
insert into stud_department values(,55)
                                   *
ERROR at line 1:
ORA-00936: missing expression


SQL> /
Enter value for stud_is: 102
Enter value for dept_id: 103
old   1: insert into stud_department values(&stud_is,&dept_id)
new   1: insert into stud_department values(102,103)

1 row created.

SQL> select * from stud_department
  2  ;

   STUD_ID    DEPT_ID
---------- ----------
       201        100
       202        100
       203        101
       102        103

SQL> create or replace trigger and stud_dept11222021
  2  after update of dept_id on stud_department
  3  for each row
  4  begin
  5  update liabrary set no_of_studs = no_of_student1
  6  where dept_id =: new.dept_id:
  7  update liabrary set no_of_studs = no_of_student-1
  8  where dept_id =: old.dept_id:
  9  end:
 10  /
create or replace trigger and stud_dept11222021
                          *
ERROR at line 1:
ORA-04070: invalid trigger name


SQL> create or replace trigger stud_dept11222021
  2  after update of dept_id on stud_department
  3  for each row
  4  begin
  5  update liabrary set no_of_studs = no_of_student+1
  6  where dept_id  = :new.dept_id ;
  7
  8
  9
 10
 11  /

Warning: Trigger created with compilation errors.

SQL> create or replace trigger stud_dept11222021
  2  after update of dept_id on stud_department
  3  for each row
  4  begin
  5  update liabrary set no_of_student = no_of_student+1
  6  where dept_id =: new.dept_id;
  7  update liabrary set no_of_student = no_of_student-1
  8  where dept_id =: old.dept_id;
  9  end;
 10  /

Warning: Trigger created with compilation errors.

SQL> create or replace trigger stud_dept11222021
  2  after update of dept_id on stud_department
  3  for each row
  4  begin
  5  update liabrary set no_of_student = no_of_student+1
  6  where dept_id = :new.dept_id;
  7  update liabrary set no_of_student = no_of_student-1
  8  where dept_id = :old.dept_id;
  9  end;
 10  /

Trigger created.

SQL> select * from liabrary
  2  ;

   DEPT_ID DEPT_NAME            NO_OF_BOOKS_COUNT NO_OF_STUDENT
---------- -------------------- ----------------- -------------
       100 computer                           500           180
       101 mechanical                         450           120
       102 electrical                         200            90
       103 civil                              300            50

SQL> update stud_department set dept_id 701 where stud_id=103;
update stud_department set dept_id 701 where stud_id=103
                                   *
ERROR at line 1:
ORA-00927: missing equal sign


SQL> update stud_department set dept_id=701 where stud_id=103;

0 rows updated.

SQL> select * from liabrary
  2  ;

   DEPT_ID DEPT_NAME            NO_OF_BOOKS_COUNT NO_OF_STUDENT
---------- -------------------- ----------------- -------------
       100 computer                           500           180
       101 mechanical                         450           120
       102 electrical                         200            90
       103 civil                              300            50

SQL> update stud_department set dept_id=103 where stud_id=203;

1 row updated.

SQL> select * from liabrary;

   DEPT_ID DEPT_NAME            NO_OF_BOOKS_COUNT NO_OF_STUDENT
---------- -------------------- ----------------- -------------
       100 computer                           500           180
       101 mechanical                         450           119
       102 electrical                         200            90
       103 civil                              300            51

SQL>
