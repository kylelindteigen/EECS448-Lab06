
#include<iostream>
#include <vector>
#include "LinkedListOfInts.h"
#include "Test.h"
using namespace std;
Test::Test()
{

}

void Test::TestLinkedListOfInts()
{
	bool empty = this->TestIsEmpty();

	bool size = this->TestSize();

	bool search = this->TestSearch();

	bool Aback = this->TestAddBack();

	bool Afront = this->TestAddFront();

	bool Rback = this->TestRemoveBack();

	bool Rfront = this->TestRemoveFront();
	if(empty){
		cout<<"[isEmpty is successful]\n";
	}
	else{
		cout<<"[isEmpty has failures]----------\n";
	}
	if(size){
		cout<<"[size is successful]\n";
	}
	else{
		cout<<"[size has failures]----------\n";
	}
	if(search){
		cout<<"[search is successful]\n";
	}
	else{
		cout<<"[search has failures]----------\n";
	}
	if(Aback){
		cout<<"[addBack is successful]\n";
	}
	else{
		cout<<"[addBack has failures]----------\n";
	}
	if(Afront){
		cout<<"[addFront is successful]\n";
	}
	else{
		cout<<"[addFront has failures]----------\n";
	}
	if(Rback){
		cout<<"[removeBack is successful]\n";
	}
	else{
		cout<<"[removeBack has failures]----------\n";
	}
	if(Rfront){
		cout<<"[removeFront is successful]\n";
	}
	else{
		cout<<"[removeFront has failures]----------\n";
	}
}

bool Test::TestIsEmpty()
{
	LinkedListOfInts List;
	bool returnVal = true;
	cout<<"[Test IsEmpty function]----------------------------------------------\n\tTest 1 IsEmpty on empty list: ";
	if(List.isEmpty()){
		cout<<"Success\n\tTest 2 IsEmpty on nonempty list: ";
	}
	else{
		returnVal = false;
		cout<<"Failed\n\tTest 2 IsEmpty on nonempty list: ";
	}
	for(int i =0; i<5; i++){
		List.addFront(i);
		List.addBack(i);
	}
	vector<int> ListVec = List.toVector();
	if(ListVec.size()>0){
		if(List.isEmpty()){
			returnVal = false;
			cout<<"Failed\n[Test IsEmpty function complete]-------------------------------------\n";
		}
		else{
			cout<<"Success\n[Test IsEmpty function complete]-------------------------------------\n";
		}
	}
	else{
		returnVal = false;
		cout<<"Unable to test because addfront and addback do not work\n[Test IsEmpty function complete]-------------------------------------\n";
	}
	return returnVal;
}

bool Test::TestSize()
{
	LinkedListOfInts List;
	bool returnVal = true;
	cout<<"[Test size function]----------------------------------------------\n\tTest 1 size on empty list: ";
	if(List.size()==0){
		cout<<"Success\n\tTest 2 size of list after addFront: ";
	}
	else{
		returnVal = false;
		cout<<"Failed\n\tTest 2 size of list after addFront: ";
	}
	for(int i =0; i<10; i++){
		List.addFront(i);
	}
	vector<int> ListVec = List.toVector();
	if(List.size()!=ListVec.size()){
		returnVal = false;
		cout<<"Failed\n\tTest 3 size of list after addBack: ";
	}
	else{
		cout<<"Success\n\tTest 3 size of list after addBack: ";
	}
	for(int i =0; i<10; i++){
		List.addBack(i);
	}
	ListVec = List.toVector();
	if(List.size()!=ListVec.size()){
		returnVal = false;
		cout<<"Failed\n\tTest 4 size of list after removeBack: ";
	}
	else{
		cout<<"Success\n\tTest 4 size of list after removeBack: ";
	}
	for(int i =0; i<5; i++){
		List.removeBack();
	}
	ListVec = List.toVector();
	if(List.size()!=ListVec.size()){
		returnVal = false;
		cout<<"Failed\n\tTest 5 size of list after removeFront: ";
	}
	else{
		cout<<"Success\n\tTest 5 size of list after removeFront: ";
	}
	for(int i =0; i<5; i++){
		List.removeFront();
	}
	ListVec = List.toVector();
	if(List.size()!=ListVec.size()){
		returnVal = false;
		cout<<"Failed\n[Test size function complete]-------------------------------------\n";
	}
	else{
		cout<<"Success\n[Test size function complete]-------------------------------------\n";
	}
	return returnVal;
}

bool Test::TestSearch()
{
	LinkedListOfInts List;
	bool returnVal = true;
	bool SearchList = true;
	cout<<"[Test search function]----------------------------------------------\n\tTest 1 search on empty list: ";
	if(!List.search(10)){
		cout<<"Success\n\tTest 2 search for last value in the list: ";
	}
	else{
		returnVal = false;
		cout<<"Failed\n\tTest 2 search for last value in the list: ";
	}
	for(int i =0; i<20; i++){
		List.addFront(i);
	}
	vector<int> ListVec = List.toVector();
	if(ListVec.size()>0){
		if(!List.search(ListVec.back())){
			returnVal = false;
			cout<<"Failed\n\tTest 3 search for first value in the list: ";
		}
		else{
			cout<<"Success\n\tTest 3 search for first value in the list: ";
		}
		if(!List.search(ListVec.front())){
			returnVal = false;
			cout<<"Failed\n\tTest 4 search through small list: ";
		}
		else{
			cout<<"Success\n\tTest 4 search through small list: ";
		}
		for(int i = ListVec.size()-1; i<1; i--){
			ListVec.pop_back();
			if(!List.search(ListVec.back())){
				SearchList = false;
			}
		}
		if(SearchList){
			cout<<"Success\n[Test search function complete]-------------------------------------\n";
		}
		else{
			returnVal = false;
			cout<<"Failed\n[Test search function complete]-------------------------------------\n";
		}
	}
	else{
		returnVal = false;
		cout<<"Unable to test because addfront does not add anything\n[Test search function complete]-------------------------------------\n";
	}
	return returnVal;
}

bool Test::TestAddBack()
{
	LinkedListOfInts List;
	bool returnVal = true;
	bool BackValExpected = true;
	cout<<"[Test addBack function]----------------------------------------------\n\tTest 1 Item was added: ";
	List.addBack(1);
	if(List.toVector().size() ==1){
		cout<<"Success\n\tTest 2 correct value added: ";
	}
	else if(List.toVector().size() >1){
		returnVal = false;
		cout<<"Failed added too many values\n\tTest 2 correct value added: ";
	}
	else{
		returnVal = false;
		cout<<"Failed\n[Test addBack function ended early no values added]----------------\n";
		return(returnVal);
	}
	if(List.toVector().back() == 1){
		cout<<"Success\n\tTest 3 Correct position: ";
	}
	else{
		returnVal = false;
		cout<<"Failed\n\tTest 3 Correct position: ";
	}
	for(int i = 1; i<10; i++){
		List.addBack(i);
		if(List.toVector().back() !=i){
			BackValExpected = false;
		}
	}
	if(BackValExpected){
		cout<<"Success\n[Test addBack function complete]-------------------------------------\n";
	}
	else{
		returnVal = false;
		cout<<"Failed\n[Test addBack function complete]-------------------------------------\n";
	}
	return returnVal;
}

bool Test::TestAddFront()
{
	LinkedListOfInts List;
	bool returnVal = true;
	bool FrontValExpected = true;
	cout<<"[Test addFront function]----------------------------------------------\n\tTest 1 Item was added: ";
	List.addFront(1);
	if(List.toVector().size() ==1){
		cout<<"Success\n\tTest 2 correct value added: ";
	}
	else if(List.toVector().size() >1){
		returnVal = false;
		cout<<"Failed added too many values\n\tTest 2 correct value added: ";
	}
	else{
		returnVal = false;
		cout<<"Failed nothing added\n[Test addFront function ended early no values added]----------------\n";
		return returnVal;
	}
	if(List.toVector().front() == 1){
		cout<<"Success\n\tTest 3 Correct position: ";
	}
	else{
		returnVal = false;
		cout<<"Failed\n\tTest 3 Correct position: ";
	}
	for(int i = 1; i<10; i++){
		List.addFront(i);
		if(List.toVector().front() !=i){
			FrontValExpected = false;
		}
	}
	if(FrontValExpected){
		cout<<"Success\n[Test addFront function complete]-------------------------------------\n";
	}
	else{
		returnVal = false;
		cout<<"Failed\n[Test addFront function complete]-------------------------------------\n";
	}
	return returnVal;
}

bool Test::TestRemoveBack()
{
	LinkedListOfInts List;
	bool returnVal = true;
	int nextBack = 0;
	bool BackValExpected = true;
	cout<<"[Test removeBack function]----------------------------------------------\n\tTest 1 Remove nothing: ";
	List.removeBack();
	if(List.toVector().size() == 0){
		cout<<"Success\n\tTest 2 Remove 1 value: ";
	}
	else{
		returnVal = false;
		cout<<"Failed\n\tTest 2 Remove 1 value: ";
	}
	List.addFront(1);
	if(List.toVector().size() == 1){
		List.removeBack();
		if(List.toVector().size() == 0){
			cout<<"Success\n\tTest 3 Remove from correct position: ";
		}
		else{
			returnVal = false;
			cout<<"Failed\n\tTest 3 Remove from correct position: ";
		}
	}
	else{
		cout<<"Failed to add value to remove\n\tTest 3 Remove from correct position: ";
	}
	for(int i = 0; i<10; i++){
		List.addFront(i);
	}
	for(int i = 9; i>0; i--){
		nextBack = List.toVector()[i-1];
		List.removeBack();
		if(List.toVector().back() != nextBack){
			BackValExpected = false;
		}
	}
	if(BackValExpected){
		cout<<"Success\n[Test RemoveBack function complete]-------------------------------------\n";
	}
	else{
		returnVal = false;
		cout<<"Failed\n[Test RemoveBack function complete]-------------------------------------\n";
	}
	return returnVal;
}

bool Test::TestRemoveFront()
{
	LinkedListOfInts List;
	bool returnVal = true;
	int nextFront = 0;
	bool FrontValExpected = true;
	cout<<"[Test removeFront function]----------------------------------------------\n\tTest 1 Remove nothing: ";
	List.removeFront();
	if(List.toVector().size() == 0){
		cout<<"Success\n\tTest 2 Remove 1 value: ";
	}
	else{
		returnVal = false;
		cout<<"Failed\n\tTest 2 Remove 1 value: ";
	}
	List.addFront(1);
	if(List.toVector().size() == 1){
		List.removeFront();
		if(List.toVector().size() == 0){
			cout<<"Success\n\tTest 3 Remove from correct position: ";
		}
		else{
			returnVal = false;
			cout<<"Failed\n\tTest 3 Remove from correct position: ";
		}
	}
	else{
		cout<<"Failed to add value to remove\n\tTest 3 Remove from correct position: ";
	}
	for(int i = 0; i<10; i++){
		List.addFront(i);
	}
	for(int i = 0; i<9; i++){
		nextFront = List.toVector()[i+1];
		List.removeFront();
		if(List.toVector().front() != nextFront){
			FrontValExpected = false;
		}
	}
	if(FrontValExpected){
		cout<<"Success\n[Test RemoveBack function complete]-------------------------------------\n";
	}
	else{
		returnVal = false;
		cout<<"Failed\n[Test RemoveBack function complete]-------------------------------------\n";
	}
	return returnVal;
}
