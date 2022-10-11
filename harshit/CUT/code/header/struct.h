struct examcenter
{
	char *examcno;
	char *examid;
	char *college_name;
	char *address;
	struct examcenter *next;
	pthread_mutex_t lock;
};

struct candidate
{
	char *examcno;
	char *examid;
	char *college_name;
	char *address;
	char *candidateid;
	char *name;
	char *start_date;
	char *end_date;
	struct candidate *next;
};