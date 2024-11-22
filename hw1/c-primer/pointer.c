// Copyright (c) 2012 MIT License by 6.172 Staff

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char * argv[]) {  // What is the type of argv? pointer to a pointer to a char
  int i = 5;
  // The & operator here gets the address of i and stores it into pi
  int * pi = &i;
  // The * operator here dereferences pi and stores the value -- 5 --
  // into j.
  int j = *pi;

  char c[] = "6.172";
  char * pc = c;  // Valid assignment: c acts like a pointer to c[0] here.
  char d = *pc;
  printf("char d = %c\n", d);  // What does this print? 
  
  // c decays to the pointer to '6' which is then assigned to the pointer pc(array decay). 
  // then d dereferences pc to get that character.
  // so it prints the char '6', more precisely "char d = 6"

  // compound types are read right to left in C.
  // pcp is a pointer to a pointer to a char, meaning that
  // pcp stores the address of a char pointer.
  char ** pcp;
  pcp = argv;  // Why is this assignment valid? b/c argv is a pointer to the first argument (in the list of args) which is a pointer to char.

  const char * pcc = c;  // pcc is a pointer to char constant
  char const * pcc2 = c;  // What is the type of pcc2? 
  
  // its the same, both are pointers to a const character, pointer can change character cant.

  // For each of the following, why is the assignment:
  *pcc = '7';  // invalid? -> because pcc is a pointer to a char constant. that cant change. 
  pcc = *pcp;  // valid? because *pcp dereferences a pointer to pointer to char into a pointer to char which is the type of pcc. 
              // and pcc itself is not constant, just the memory location it original pointed to was. 
  pcc = argv[0];  // valid? indexing into the array of pointers gets pointer to char. and pcc is not constant. 

  char * const cp = c;  // cp is a const pointer to char
  // For each of the following, why is the assignment:
  cp = *pcp;  // invalid? because cp is a constant pointer. 
  cp = *argv;  // invalid? same reason
  *cp = '!';  // valid? only the pointer is constant, the value it points to need not be.

  const char * const cpc = c;  // cpc is a const pointer to char const
  // For each of the following, why is the assignment:
  cpc = *pcp;  // invalid? cant change constant pointer
  cpc = argv[0];  // invalid? same
  *cpc = '@';  // invalid? cant change constant value.

  return 0;
}
