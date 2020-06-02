void merge( Node*& start1,  Node*& end1, Node*& start2,  Node*& end2)
{
	 Node* tmp = nullptr;

	if (start1->x > start2->x) 
	{
		std::swap(start1, start2);
		std::swap(end1, end2);
	}

	// Merging remaining nodes 
	Node* L1_start = start1;
	Node* L1_end = end1;
	Node* L2_start = start2;
	Node* L2_end = end2;


	while (L1_start != L1_end && L2_start != L2_end)
	{
		if (L1_start->next->x > L2_start->x)
		{
			tmp = L2_start->next;
			L2_start->next = L1_start->next;
			L1_start->next = L2_start;
			L2_start = tmp;
		}

		L1_start = L1_start->next;
	}

	//jesli ktoras czesc listy skonczy sie szybciej niz druga
	if (L1_start == L1_end)
		L1_start->next = L2_start;
	else
		end2 = end1;



}

int llen(Node* head)
{
	int c = 0;
	while (head) 
	{
		head = head->next;
		c++;
	}
	return c;
}

void mergeSort(struct Node*& head)
{
	if (!head || !head->next) return;
	
	Node* start1 = head, *end1, *start2, *end2;
	Node* endList=nullptr;

	int leng = llen(head);

	//petla zaczynajaca od 1 i idaca *2 -> na poczatku mamy X posotrowanych tablic o rozmiarze 1, pozniej 2,4,8 itd
	for (int act_size = 1; act_size < leng; act_size = act_size * 2)
	{
		start1 = head;
		bool first = true;

		while (start1)
		{  
			// Ustawiam koniec na pozycje odpowiadaj¹c¹ i
			int elements = act_size-1;
			
			end1 = start1;
			//przesuwa end1 tworzac odpowiednia ,,tablice" miedzy start1 a end1
			while (elements && end1->next)
			{
				elements--;
				end1 = end1->next;
			}

			
			start2 = end1->next;
	
			if (!start2)	
				break;

			elements = act_size-1;

			end2 = start2;
			while (elements && end2->next)
			{	
				elements--;
				end2 = end2->next;
			}
			
			Node *tmp = end2->next;

			merge(start1, end1, start2, end2);
 
			

			if (first)
			{	
				first = false;

				//head jest poczatkiem listy juz posortowanej
				head = start1;
			}
			else
				endList->next = start1;

			endList = end2;
			start1 = tmp;
	
		}
		
		endList->next = start1;
	}
}
