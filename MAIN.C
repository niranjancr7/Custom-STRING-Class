#include<iostream>
#include<cstdlib>
using namespace std;
class STRING
{
	char *s;
	public:
	STRING()
	{
		s=new char[1];
		*s='\0';
	}

	STRING(const char *n)
	{
		int len,i;
		for(len=0;n[len];len++);
		s=new char[len+1];
		for(i=0;n[i];i++)
			s[i]=n[i];
		s[i]='\0';
	}

	STRING(const STRING &n)
	{
		int len,i;
		for(len=0;n.s[len];len++);
		s=new char[len+1];
		for(i=0;n.s[i];i++)
			s[i]=n.s[i];
		s[i]='\0';
	}

	STRING& operator=(const STRING &n)
	{
		int len,i;
		for(len=0;n.s[len];len++);
		char *temp=new char[len+1];
		for(i=0;n.s[i];i++)
			temp[i]=n.s[i];
		temp[i]='\0';
		delete []s;
		s=temp;
		return *this;
	}

	STRING operator+(const STRING &n)
	{
		int len,i,len1;
		for(len=0;n.s[len];len++);
		for(len1=0;s[len1];len1++);
		char *temp=new char[len+len1+1];
		int j=0;
		for(i=0;s[i];i++)
		{
			temp[j]=s[i];
			j++;
		}
		for(i=0;n.s[i];i++)
		{
			temp[j]=n.s[i];
			j++;
		}
		temp[j]='\0';
		STRING result(temp);
		delete []temp;
		return result;
	}

	char& operator[](int n)
	{
		int len;
		for(len = 0; s[len] != '\0'; len++);
		if(n < 0 || n >= len)
		{
			cout << "Invalid index" << endl;
			exit(1);
		}
		return s[n];
	}

	bool operator==(const STRING &n)
	{
		int i,flag=0;
		for(i=0; s[i]!='\0' && n.s[i]!='\0'; i++)
		{
		if(s[i]==n.s[i])
			continue;
		else
		{
			flag=1;
			break;
		}
		}
		if(flag==0 && s[i]=='\0' && n.s[i]=='\0')
			return 1;
		else
			return 0;
	}

	bool operator!=(const STRING &n)
	{
		int i,flag=0;
		for(i=0; s[i]!='\0' && n.s[i]!='\0'; i++)
		{
		if(s[i]==n.s[i])
			continue;
		else
		{
			flag=1;
			break;
		}
		}
		if(flag==0 && s[i]=='\0' && n.s[i]=='\0')
			return 0;
		else
			return 1;
	}

	bool operator>(const STRING &n)
	{
		int i; 
		for(i = 0; s[i] != '\0' && n.s[i] != '\0'; i++)
		{
			if(s[i] > n.s[i])
				return 1;
			else if(s[i] < n.s[i])
				return 0;
		}
		if(s[i] != '\0' && n.s[i] == '\0')
			return 1;
		else
			return 0;
	}

	bool operator<(const STRING &n)
	{
		int i; 
		for(i=0;s[i]!='\0' && n.s[i]!='\0';i++)
		{
			if(s[i] < n.s[i])
				return 1;
			else if(s[i] > n.s[i])
				return 0;
		}
		if(s[i]=='\0' && n.s[i]!='\0')
			return 1;
		else
			return 0;
	}

	bool operator>=(const STRING &n)
	{
		int i;
		for(i=0;s[i]!='\0' && n.s[i]!='\0';i++)
		{
			if(s[i] > n.s[i])
				return 1;
			else if(s[i] < n.s[i])
				return 0;
		}
		if(s[i]=='\0' && n.s[i]=='\0')
			return 1;
		if(s[i]!='\0' && n.s[i]=='\0')
			return 1;
		return 0;
	}

	bool operator<=(const STRING &n)
	{
		int i;
		for(i=0;s[i]!='\0' && n.s[i]!='\0';i++)
		{
			if(s[i] < n.s[i])
				return 1;
			else if(s[i] > n.s[i])
				return 0;
		}
		if(s[i]=='\0' && n.s[i]=='\0')
			return 1;
		if(s[i]=='\0' && n.s[i]!='\0')
			return 1;
		return 0;
	}

	friend istream & operator >> (istream & in,STRING & n);
	friend ostream & operator << (ostream & out,const STRING & n);
	friend STRING & strcpy(STRING &s2,const STRING &s1);
        friend STRING & strncpy(STRING &s2,const STRING &s1,int n);
        friend int strcmp(const STRING &s2,const STRING &s1);
        friend int strncmp(const STRING &s2,const STRING &s1,int n);
        friend STRING & strcat(STRING &s2,const STRING &s1);
        friend STRING & strncat(STRING &s2,const STRING &s1,int n);
        friend STRING & strrev(STRING &s1);
        friend STRING & strupr(STRING &s1);
        friend STRING & strlwr(STRING &s1);
        friend char * strchr(const STRING &s1,char ch);
        friend char * strrchr(const STRING &s1,char ch);
        friend char * strstr(const STRING &s1,const STRING &s2);
        friend int strlen(const STRING &s1);

	~STRING()
	{
		delete []s;
		s=nullptr;
	}
};

istream & operator >> (istream & in,STRING & n)
{
    char temp[100];
    in.getline(temp,100);
    int len = 0;
    while (temp[len] != '\0')
        len++;
    char *p = new char[len + 1];
    int i;   
    for (i = 0; temp[i] != '\0'; i++)
        p[i] = temp[i];
    p[i] = '\0';
    delete[] n.s;
    n.s = p;
    return in;
}

ostream & operator << (ostream & out,const STRING & n)
{
	out << n.s;
	return out;
}

STRING & strcpy(STRING &s2,const STRING &s1)
{
	if(&s2 == &s1)
        return s2;
	int len,i;
	for(len=0;s1.s[len]!='\0';len++);
	char *temp=new char[len+1];
	for(i=0;s1.s[i]!='\0';i++)
		temp[i]=s1.s[i];
	temp[i]='\0';
	delete []s2.s;
	s2.s=temp;
	return s2;
}

STRING & strncpy(STRING &s2,const STRING &s1,int n)
{
	if(n<=0)
		return s2;
	if(&s2 == &s1)
        return s2;
	int i;
	char *temp=new char[n+1];
	for(i=0;s1.s[i]!='\0' && i<n ;i++)
	{
		temp[i]=s1.s[i];
	}
	temp[i]='\0';
	delete []s2.s;
	s2.s=temp;
	return s2;
}

int strcmp(const STRING &s2, const STRING &s1)
{
    int i;
    for(i = 0; s1.s[i] != '\0' && s2.s[i] != '\0'; i++)
    {
        if(s2.s[i] != s1.s[i])
            return s2.s[i] - s1.s[i];
    }
    if(s2.s[i] == '\0' && s1.s[i] == '\0')
        return 0;
    else if(s2.s[i] == '\0')
        return -1;
    else
        return 1;
}


int strncmp(const STRING &s2,const STRING &s1,int n)
{
	if(n<=0)
		return 0;
	int i;
	for(i=0;i<n && s1.s[i]!='\0' && s2.s[i]!='\0' ;i++)
	{
		if(s2.s[i] != s1.s[i])
			return s2.s[i] - s1.s[i];
	}
	if(i==n)
		return 0;
	return s2.s[i] - s1.s[i];
}

STRING & strcat(STRING &s2,const STRING &s1)
{
	int src_len,dest_len;
	for(src_len=0;s1.s[src_len];src_len++);
	for(dest_len=0;s2.s[dest_len];dest_len++);
	char *temp=new char[src_len+dest_len+1];
	int i,j=0;
	for(i=0;s2.s[i];i++)
	{
		temp[j]=s2.s[i];
		j++;
	}
	for(i=0;s1.s[i];i++)
	{
		temp[j]=s1.s[i];
		j++;
	}
	temp[j]='\0';
	delete []s2.s;
	s2.s=temp;
	return s2;
}

STRING & strncat(STRING &s2,const STRING &s1,int n)
{
	if(n<=0)
		return s2;
	int dest_len;
	for(dest_len=0;s2.s[dest_len];dest_len++);
	char *temp=new char[dest_len+n+1];
	int i,j=0;
	for(i=0;s2.s[i];i++)
	{
		temp[j]=s2.s[i];
		j++;
	}
	for(i=0;s1.s[i] && i<n ;i++)
	{
		temp[j]=s1.s[i];
		j++;
	}
	temp[j]='\0';
	delete []s2.s;
	s2.s=temp;
	return s2;
}

STRING & strrev(STRING &s1)
{
	char *p,*q;
	int len,temp;
	for(len=0;s1.s[len];len++);
	if(len<2)
		return s1;
	p=s1.s;
	q=p+len-1;
	while(p<q)
	{
		temp=*p;
		*p=*q;
		*q=temp;
		p++;
		q--;
	}
	return s1;
}

STRING & strupr(STRING &s1)
{
	int i;
	for(i=0;s1.s[i];i++)
	{
		if(s1.s[i] >= 'a' && s1.s[i] <='z')
			s1.s[i]=s1.s[i]-32;
	}
	return s1;
}

STRING & strlwr(STRING &s1)
{
	int i;
	for(i=0;s1.s[i];i++)
	{
		if(s1.s[i] >= 'A' && s1.s[i] <='Z')
			s1.s[i]=s1.s[i]+32;
	}
	return s1;
}

char * strchr(const STRING &s1,char ch)
{
	int i;
	if(ch=='\0')
	{
		for(i=0;s1.s[i];i++);
		return &s1.s[i];
	}
	for(i=0;s1.s[i];i++)
	{
		if(s1.s[i]==ch)
			return &s1.s[i]; 
	}
	return 0;
}

char * strrchr(const STRING &s1,char ch)
{
	int i;
	if(ch=='\0')
	{
		for(i=0;s1.s[i];i++);
		return &s1.s[i];
	}
	char *p=0;
	for(i=0;s1.s[i];i++)
	{
		if(s1.s[i]==ch)
		{
		p=&s1.s[i];
		}
	}
	return p;
}

char* strstr(const STRING &s1, const STRING &s2)
{
    int i, j;
    if(s2.s[0] == '\0')
        return s1.s;
    for(i = 0; s1.s[i] != '\0'; i++)
    {
        for(j = 0; s2.s[j] != '\0'; j++)
        {
            if(s1.s[i+j] == '\0' || s1.s[i+j] != s2.s[j])
                break;
        }
        if(s2.s[j] == '\0')
            return &s1.s[i];
    }
    return 0;
}

int strlen(const STRING &s1)
{
	int len;
	for(len=0;s1.s[len];len++);
	return len;	
}

int main()
{
	STRING s1("one");
	STRING s2("Two");
	s2=s1;
	s2=STRING("three");
	s2=STRING("Four");
	cout << s1 << endl;
	cout << s2 << endl;
	return 0;
}

