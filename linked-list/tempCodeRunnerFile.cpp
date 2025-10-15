Node *temp=START;

	while(temp->info!=2){
		temp=temp->Next;
	}

	delAft(&temp);
	cout<<"\nAfter Deletion : ";
	Traverse(START);