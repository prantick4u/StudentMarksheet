typedef struct Subject{
	const char* _subject;
	int _mark;
}sub;

typedef struct MarkSheet {
	sub* _firstTerm;
	sub* _secondTerm;
	sub* _thirdTerm;
	sub* _fourthTerm;
}markSheet;

typedef struct Student
{
	markSheet* _terms;
	int _roll;
}student;

enum subjectType {Math, Science, Literature, Biology, Mechanics };
