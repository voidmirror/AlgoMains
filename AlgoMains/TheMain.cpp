//#include <iostream>
////#include <algorithm>
//using namespace std;
//
//struct StackNum {
//	char val;
//	StackNum* pnext;
//};
//
//struct StackSym {
//	char val;
//	StackSym* pnext;
//};
//
//StackNum* numpush(StackNum* phead, char v)
//{
//	StackNum *p = (StackNum*)malloc(sizeof(StackNum));
//	p->val = v;
//	p->pnext = phead;
//	return p;
//}
//
//StackSym* chpush(StackSym* phead, char v)
//{
//	StackSym *p = (StackSym*)malloc(sizeof(StackSym));
//	p->val = v;
//	p->pnext = phead;
//	return p;
//}
//
//StackNum* numpop(StackNum* phead)
//{
//	StackNum *p = phead->pnext;
//	free(phead);
//	return p;
//}
//
//StackSym* chpop(StackSym* phead)
//{
//	StackSym *p = phead->pnext;
//	free(phead);
//	return p;
//}
//
//int main() {
//	StackNum *numbers = 0;
//	StackSym *symbols = 0;
//
//	///*numbers = numpush(numbers, 4);
//	//cout << numbers->val;
//	//numbers = numpop(numbers);
//
//	//symbols = chpush(symbols, '+');
//	//cout << symbols->val;
//	//symbols = chpop(symbols);*/
//
//	char input[100];
//	char output[100];
//	int outpos = 0;
//	int figures = 0;
//
//	// *********** test ***********
//	cin >> input;
//
//	symbols = chpush(symbols, '=');
//	for (int i = 0; i < strlen(input); i++) {
//		///*if (input[i] = '+' && symbols->val) {
//		//	
//		//}
//		//else if (input[i] = '+' && symbols->val == '+') {
//
//		//}*/
//
//		///*if (input[i] != '+') {
//		//	output[outpos] = input[i];
//		//	outpos++;
//		//}
//		//else {
//		//	if (symbols && input[i] == '+') {
//		//		output[outpos] = symbols->val;
//		//		outpos++;
//		//		symbols = chpop(symbols);
//		//		symbols = chpush(symbols, input[i]);
//		//	}
//		//	else {
//		//		symbols = chpush(symbols, input[i]);
//		//	}
//		//}*/
//		
//		switch (input[i]) {
//		case '+' :
//			if (symbols->val != '+' && symbols->val != '-' && symbols->val != '*' && symbols->val != '/') {
//				symbols = chpush(symbols, input[i]);
//			}
//			else {
//				output[outpos] = symbols->val;
//				outpos++;
//				symbols = chpop(symbols);
//				symbols = chpush(symbols, input[i]);
//			}
//			break;
//		case '-' :
//			if (symbols->val != '+' && symbols->val != '-' && symbols->val != '*' && symbols->val != '/') {
//				symbols = chpush(symbols, input[i]);
//			}
//			else {
//				output[outpos] = symbols->val;
//				outpos++;
//				symbols = chpop(symbols);
//				symbols = chpush(symbols, input[i]);
//			}
//			break;
//		case '*' :
//			if (symbols->val != '*' && symbols->val != '/') {
//				symbols = chpush(symbols, input[i]);
//			}
//			else {
//				output[outpos] = symbols->val;
//				outpos++;
//				symbols = chpop(symbols);
//				symbols = chpush(symbols, input[i]);
//			}
//			break;
//		case '/':
//			if (symbols->val != '*' && symbols->val != '/') {
//				symbols = chpush(symbols, input[i]);
//			}
//			else {
//				output[outpos] = symbols->val;
//				outpos++;
//				symbols = chpop(symbols);
//				symbols = chpush(symbols, input[i]);
//			}
//			break;
//		default :
//			figures++;
//			numbers = numpush(numbers, input[i]);
//			if (input[i + 1] <= '9' && input[i + 1] >= '0') {
//				char* temp;
//				temp = (char*)malloc(sizeof(char)*figures);
//				for (int j = 0; j < figures; j++) {
//					temp[j] = numbers->val;
//					numbers = numpop(numbers);
//				}
//				for (int j = 0; j < ceil(figures / 2); j++) {
//					swap(temp[j], temp[figures - 1 - j]);
//				}
//				for (int j = 0; j < figures; j++) {
//					output[outpos] = temp[j];
//				}
//			}
//			else {
//				output[outpos] = input[1]; // change!!
//			}
//		}
//	}
//
//	outpos++;
//	output[outpos] = '\0';
//	cout << output << endl;
//}
