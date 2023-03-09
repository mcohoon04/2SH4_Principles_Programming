/*
 * SLLSet.cpp
 *
 *  Created on: Nov. 17, 2021
 *      Author: moham
 */


#include "SLLSet.h"
#include <iostream>

SLLSet::SLLSet()
{
	size = 0;
	head = NULL;
}
SLLSet::SLLSet(int sortedArray[], int arrSize)
{
	//set class variable size equal to size of the given array
		size = arrSize;
		head = NULL;
		//create the linked list
		for(int i=size-1;i>=0;i--){
			//to check if its first node
			if(head == NULL){
				SLLNode* newNode = new SLLNode(sortedArray[i],NULL);
				head = newNode;
			}
			else{
				SLLNode* newNode = new SLLNode(sortedArray[i],head);
				head = newNode;
			}
		}
}
int SLLSet::getSize()
{
	return size;
}
SLLSet SLLSet::copy()
{
	int values[size];
	SLLNode* temp = head;
	for(int i=0;i<size;i++){
		int val = temp->value;
		values[i]=val;
		if(temp->next==NULL){
			break;
		}
		else{
			temp=temp->next;
		}
	}
	SLLSet set = SLLSet(values,size);
	return set;
}
bool SLLSet::isIn(int v)
{
	SLLNode* temp = head;
	for(int i=0;i<size;i++){
		int val = temp->value;
		if(val==v){
			return true;
		   }
		else{
			if(temp->next==NULL){
				break;
			}
			else{
				temp=temp->next;
			}
		}
	}
	return false;
}
void SLLSet::add(int v)
{
	if(!(this->isIn(v))){
	        if(head==NULL||size==0){
	            SLLNode* newNode = new SLLNode(v,NULL);
	            head = newNode;
	        }
	        else{
	            SLLNode* temp1 = head;
	            SLLNode* temp2 = temp1->next;
	            while(1){
	    		    if(v>temp1->value && temp2!=NULL && v<temp2->value){
	    		        SLLNode* newNode = new SLLNode(v,NULL);
	    		        temp1->next = newNode;
	    		        newNode->next = temp2;
	    		        break;
	    		    }
	    		    else if(v>temp1->value && temp2==NULL){
	    		        SLLNode* newNode = new SLLNode(v,NULL);
	    		        temp1->next = newNode;
	    		        break;
	    		   }
	    		   else if(v<temp1->value && temp1==head){
	    		        SLLNode* newNode = new SLLNode(v,temp1);
	    		        head = newNode;
	    		        break;
	    		   }
	    		   else{
	    		       temp1=temp1->next;
	    		       temp2=temp2->next;
	    		   }
		   }
	    }
	       size++;
	    }
}
void SLLSet::remove(int v)
{
	if(this->isIn(v)){
	       SLLNode* pred = head;
	       SLLNode* curr = pred->next;
	       if(pred->value==v){
	               head = curr;
	               delete pred;

	       }
	       else{
	           while(curr!=NULL){
	               if(curr->value==v){
	                    pred->next=curr->next;
	                    delete curr;
	                    break;
	                }
	                pred = curr;
	                curr = curr->next;
	            }
	       }
	       size--;
	   }
}
SLLSet SLLSet::setUnion(SLLSet s)
{
	SLLSet Union = s.copy();
	SLLNode* temp = head;
	while(temp!=NULL){
		Union.add(temp->value);
	    temp=temp->next;
	    }
	return Union;
}
SLLSet SLLSet::intersection(SLLSet s)
{
	SLLSet inter = SLLSet();
	SLLNode* temp = head;
	while(temp!=NULL){
		if(s.isIn(temp->value)){
			inter.add(temp->value);
		}
	    temp=temp->next;
	}
	return inter;
}
SLLSet SLLSet::difference(SLLSet s)
{
	SLLSet diff = SLLSet();
	SLLNode* temp = head;
	while(temp!=NULL){
		if(!s.isIn(temp->value)){
			diff.add(temp->value);
		}
		temp=temp->next;
	}
	return diff;
}
SLLSet SLLSet::setUnion(SLLSet sArray[],int size)
{
	SLLSet Union = SLLSet();
	for(int i=0;i<size;i++){
		Union=sArray[i].setUnion(Union);
	}
	return Union;
}
string SLLSet::toString()
{
	string set;
	SLLNode* temp = head;
	if(head==NULL){
		set="";
	}
	else{
		while(temp!=NULL){
			int val = temp->value;
			set.append(to_string(val));
			if(temp->next!=NULL){
				set.append(", ");
			}
			temp=temp->next;
		}
	}
    return set;
}

