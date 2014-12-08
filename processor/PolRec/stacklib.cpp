#include "stacklib.h"

void create_stack(struct item **begin){
    (*begin)=(struct item*)calloc(1,sizeof(**begin));
    (**begin).value=0;
    (**begin).next=NULL;
}

void push_stack(struct item **current, type element){
    assert(isExist_stack(*current));
    struct item *temp=*current;
    *current=(struct item*)calloc(1,sizeof(**current));
    (**current).value=element;
    (**current).next=temp;
}

type pop_stack(struct item **current){
    assert(isExist_stack(*current));  //when assert showed, you know what the error
    assert((!isEmpty_stack(*current)));  //when assert showed, you know what the error
    type element=(**current).value;
    struct item *temp=*current;
    *current=(**current).next;
    free(temp);
    return element;
}

void delete_stack(struct item** current){
    assert(isExist_stack(*current));
    struct item* temp=NULL;
    while ((**current).next!=NULL){
        temp=*current;
        *current=(**current).next;
        free(temp);
    };
    free(*current);
    (*current)=NULL;
}

bool isEmpty_stack(struct item *current){
    assert(isExist_stack(current));
    if ((*current).next==NULL) return true; else return false;
}

bool isExist_stack(struct item *current){
    if (current!=NULL) return true; else return false;
}

int getCount_stack(struct item *current){
    assert(isExist_stack(current));
    int number_of_elements=0;
    while ((*current).next!=NULL){
        number_of_elements++;
        current=(*current).next;
    }
    return number_of_elements;
}

