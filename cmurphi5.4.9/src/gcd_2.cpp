/******************************
  Program "gcd_2.m" compiled by "Caching Murphi Release 5.4.9"

  Murphi Last Compiled date: "Mar 31 2017"
 ******************************/

/********************
  Parameter
 ********************/
#define MURPHI_VERSION "Caching Murphi Release 5.4.9"
#define MURPHI_DATE "Mar 31 2017"
#define PROTOCOL_NAME "gcd_2"
#define BITS_IN_WORLD 456
#define ALIGN

/********************
  Include
 ********************/
#include "mu_prolog.hpp"

/********************
  Decl declaration
 ********************/

class mu_1_val_t: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu_1_val_t& val) { return mu__byte::operator=((int) val); };
  mu_1_val_t (const char *name, int os): mu__byte(0, 16, 5, name, os) {};
  mu_1_val_t (void): mu__byte(0, 16, 5) {};
  mu_1_val_t (int val): mu__byte(0, 16, 5, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu_1_val_t mu_1_val_t_undefined_var;

class mu_1_arr_t
{
 public:
  mu_1_val_t array[ 17 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( const char *n, int os);
  void set_self_2( const char *n, const char *n2, int os);
  void set_self_ar( const char *n, const char *n2, int os);
  mu_1_arr_t (const char *n, int os) { set_self(n, os); };
  mu_1_arr_t ( void ) {};
  virtual ~mu_1_arr_t ();
  mu_1_val_t& operator[] (int index) /* const */
  {
#ifndef NO_RUN_TIME_CHECKING
    if ( ( index >= 0 ) && ( index <= 16 ) )
      return array[ index - 0 ];
    else {
      if (index==UNDEFVAL) 
	Error.Error("Indexing to %s using an undefined value.", name);
      else
	Error.Error("%d not in index range of %s.", index, name);
      return array[0];
    }
#else
    return array[ index - 0 ];
#endif
  };
  mu_1_arr_t& operator= (const mu_1_arr_t& from)
  {
    for (int i = 0; i < 17; i++)
      array[i].value(from.array[i].value());
    return *this;
  }

friend int CompareWeight(mu_1_arr_t& a, mu_1_arr_t& b)
  {
    int w;
    for (int i=0; i<17; i++) {
      w = CompareWeight(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
friend int Compare(mu_1_arr_t& a, mu_1_arr_t& b)
  {
    int w;
    for (int i=0; i<17; i++) {
      w = Compare(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    for (int i=0; i<17; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<17; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 17; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 17; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 17; i++) array[i].reset(); };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 17; i++)
      array[i].to_state(thestate);
  };

  void print()
  {
    for (int i = 0; i < 17; i++)
      array[i].print(); };

  void print_diff(state *prevstate)
  {
    for (int i = 0; i < 17; i++)
      array[i].print_diff(prevstate);
  };
};

  void mu_1_arr_t::set_self_ar( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1_arr_t::set_self_2( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1_arr_t::set_self( const char *n, int os)
{
  char* s;
  name = (char *)n;
  for(int i = 0; i < 17; i++) {
    array[i].set_self_ar(n, s=tsprintf("%d",i + 0), i * 8 + os);
    delete[] s;
  }
};
mu_1_arr_t::~mu_1_arr_t()
{
}
/*** end array declaration ***/
mu_1_arr_t mu_1_arr_t_undefined_var;

class mu_1_cmp_type
{
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self_2( const char *n, const char *n2, int os);
  void set_self_ar( const char *n, const char *n2, int os);
  void set_self(const char *n, int os);
  mu_1_val_t mu_length;
  mu_1_arr_t mu_arr;
  mu_1_cmp_type ( const char *n, int os ) { set_self(n,os); };
  mu_1_cmp_type ( void ) {};

  virtual ~mu_1_cmp_type(); 
friend int CompareWeight(mu_1_cmp_type& a, mu_1_cmp_type& b)
  {
    int w;
    w = CompareWeight(a.mu_length, b.mu_length);
    if (w!=0) return w;
    w = CompareWeight(a.mu_arr, b.mu_arr);
    if (w!=0) return w;
  return 0;
}
friend int Compare(mu_1_cmp_type& a, mu_1_cmp_type& b)
  {
    int w;
    w = Compare(a.mu_length, b.mu_length);
    if (w!=0) return w;
    w = Compare(a.mu_arr, b.mu_arr);
    if (w!=0) return w;
  return 0;
}
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    mu_length.MultisetSort();
    mu_arr.MultisetSort();
  }
  void print_statistic()
  {
    mu_length.print_statistic();
    mu_arr.print_statistic();
  }
  void clear() {
    mu_length.clear();
    mu_arr.clear();
 };
  void undefine() {
    mu_length.undefine();
    mu_arr.undefine();
 };
  void reset() {
    mu_length.reset();
    mu_arr.reset();
 };
  void print() {
    mu_length.print();
    mu_arr.print();
  };
  void print_diff(state *prevstate) {
    mu_length.print_diff(prevstate);
    mu_arr.print_diff(prevstate);
  };
  void to_state(state *thestate) {
    mu_length.to_state(thestate);
    mu_arr.to_state(thestate);
  };
virtual bool isundefined() { Error.Error("Checking undefinedness of a non-base type"); return TRUE;}
virtual bool ismember() { Error.Error("Checking membership for a non-base type"); return TRUE;}
  mu_1_cmp_type& operator= (const mu_1_cmp_type& from) {
    mu_length.value(from.mu_length.value());
    mu_arr = from.mu_arr;
    return *this;
  };
};

  void mu_1_cmp_type::set_self_ar( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1_cmp_type::set_self_2( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1_cmp_type::set_self(const char *n, int os)
{
  name = (char *)n;

  if (name) mu_length.set_self_2(name, ".length", os + 0 ); else mu_length.set_self_2(NULL, NULL, 0);
  if (name) mu_arr.set_self_2(name, ".arr", os + 8 ); else mu_arr.set_self_2(NULL, NULL, 0);
}

mu_1_cmp_type::~mu_1_cmp_type()
{
}

/*** end record declaration ***/
mu_1_cmp_type mu_1_cmp_type_undefined_var;

/*** Variable declaration ***/
mu_1_val_t mu_x("x",0);

/*** Variable declaration ***/
mu_1_val_t mu_y("y",8);

/*** Variable declaration ***/
mu_1_val_t mu_r("r",16);

/*** Variable declaration ***/
mu_1_val_t mu_temp("temp",24);

/*** Variable declaration ***/
mu_1_arr_t mu_arr_i("arr_i",32);

/*** Variable declaration ***/
mu_1_cmp_type mu_arr_1("arr_1",168);

/*** Variable declaration ***/
mu_1_cmp_type mu_arr_xy("arr_xy",312);

void mu_gcd(mu_1_val_t& mu_x, mu_1_val_t& mu_y, mu_1_val_t& mu_r)
{
{
  bool mu__while_expr_1;  mu__while_expr_1 = (mu_r) != (0);
int mu__counter_0 = 0;
while (mu__while_expr_1) {
if ( ++mu__counter_0 > args->loopmax.value )
  Error.Error("Too many iterations in while loop.");
{
if (mu_y.isundefined())
  mu_x.undefine();
else
  mu_x = mu_y;
if (mu_r.isundefined())
  mu_y.undefine();
else
  mu_y = mu_r;
mu_r = (mu_x) % (mu_y);
};
mu__while_expr_1 = (mu_r) != (0);
}
};
mu_y.print();
};
/*** end procedure declaration ***/

void mu_commonDivdors(const mu_1_val_t& mu_x, const mu_1_val_t& mu_y, mu_1_cmp_type& mu_cmp)
{
/*** Variable declaration ***/
mu_1_val_t mu_a("a",0);

/*** Variable declaration ***/
mu_1_val_t mu_b("b",8);

/*** Variable declaration ***/
mu_1_val_t mu_temp("temp",16);

/*** Variable declaration ***/
mu_1_val_t mu_i("i",24);

/*** Variable declaration ***/
mu_1_val_t mu_j("j",32);

/*** Variable declaration ***/
mu_1_arr_t mu_arr("arr",40);

if (mu_x.isundefined())
  mu_a.undefine();
else
  mu_a = mu_x;
if (mu_y.isundefined())
  mu_b.undefine();
else
  mu_b = mu_y;
if (mu_y.isundefined())
  mu_temp.undefine();
else
  mu_temp = mu_y;
mu_i = 0;
if ( (mu_a) < (mu_b) )
{
if (mu_a.isundefined())
  mu_temp.undefine();
else
  mu_temp = mu_a;
}
else
{
if (mu_b.isundefined())
  mu_temp.undefine();
else
  mu_temp = mu_b;
}
{
  bool mu__while_expr_3;  mu__while_expr_3 = (mu_temp) > (0);
int mu__counter_2 = 0;
while (mu__while_expr_3) {
if ( ++mu__counter_2 > args->loopmax.value )
  Error.Error("Too many iterations in while loop.");
{
bool mu__boolexpr4;
  if (!(((mu_a) % (mu_temp)) == (0))) mu__boolexpr4 = FALSE ;
  else {
  mu__boolexpr4 = (((mu_b) % (mu_temp)) == (0)) ; 
}
if ( mu__boolexpr4 )
{
if (mu_temp.isundefined())
  mu_cmp.mu_arr[mu_i].undefine();
else
  mu_cmp.mu_arr[mu_i] = mu_temp;
mu_i = (mu_i) + (1);
}
mu_temp = (mu_temp) - (1);
};
mu__while_expr_3 = (mu_temp) > (0);
}
};
if (mu_i.isundefined())
  mu_cmp.mu_length.undefine();
else
  mu_cmp.mu_length = mu_i;
};
/*** end procedure declaration ***/

mu_0_boolean mu_compare(mu_1_cmp_type& mu_ar_1,mu_1_cmp_type& mu_ar_2)
{
/*** Variable declaration ***/
mu_1_val_t mu_i("i",0);

if ( (mu_ar_1.mu_length) == (mu_ar_2.mu_length) )
{
{
int mu__ub5 = (mu_ar_1.mu_length) - (1);
for (int mu_i = 0; mu_i <= mu__ub5; mu_i += 1) {
if ( (mu_ar_1.mu_arr[mu_i]) != (mu_ar_2.mu_arr[mu_i]) )
{
return mu_false;
}
};
};
return mu_true;
}
else
{
return mu_false;
}
	Error.Error("The end of function compare reached without returning values.");
};
/*** end function declaration ***/





/********************
  The world
 ********************/
void world_class::clear()
{
  mu_x.clear();
  mu_y.clear();
  mu_r.clear();
  mu_temp.clear();
  mu_arr_i.clear();
  mu_arr_1.clear();
  mu_arr_xy.clear();
}
void world_class::undefine()
{
  mu_x.undefine();
  mu_y.undefine();
  mu_r.undefine();
  mu_temp.undefine();
  mu_arr_i.undefine();
  mu_arr_1.undefine();
  mu_arr_xy.undefine();
}
void world_class::reset()
{
  mu_x.reset();
  mu_y.reset();
  mu_r.reset();
  mu_temp.reset();
  mu_arr_i.reset();
  mu_arr_1.reset();
  mu_arr_xy.reset();
}
void world_class::print()
{
  static int num_calls = 0; /* to ward off recursive calls. */
  if ( num_calls == 0 ) {
    num_calls++;
  mu_x.print();
  mu_y.print();
  mu_r.print();
  mu_temp.print();
  mu_arr_i.print();
  mu_arr_1.print();
  mu_arr_xy.print();
    num_calls--;
}
}
void world_class::print_statistic()
{
  static int num_calls = 0; /* to ward off recursive calls. */
  if ( num_calls == 0 ) {
    num_calls++;
  mu_x.print_statistic();
  mu_y.print_statistic();
  mu_r.print_statistic();
  mu_temp.print_statistic();
  mu_arr_i.print_statistic();
  mu_arr_1.print_statistic();
  mu_arr_xy.print_statistic();
    num_calls--;
}
}
void world_class::print_diff( state *prevstate )
{
  if ( prevstate != NULL )
  {
    mu_x.print_diff(prevstate);
    mu_y.print_diff(prevstate);
    mu_r.print_diff(prevstate);
    mu_temp.print_diff(prevstate);
    mu_arr_i.print_diff(prevstate);
    mu_arr_1.print_diff(prevstate);
    mu_arr_xy.print_diff(prevstate);
  }
  else
print();
}
void world_class::to_state(state *newstate)
{
  mu_x.to_state( newstate );
  mu_y.to_state( newstate );
  mu_r.to_state( newstate );
  mu_temp.to_state( newstate );
  mu_arr_i.to_state( newstate );
  mu_arr_1.to_state( newstate );
  mu_arr_xy.to_state( newstate );
}
void world_class::setstate(state *thestate)
{
}


/********************
  Rule declarations
 ********************/
/******************** RuleBase0 ********************/
class RuleBase0
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    return tsprintf("Rule 1");
  }
  bool Condition(unsigned r)
  {
    return (mu_x) < (mu_y);
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 0;
    while (what_rule < 1 )
      {
	if ( ( TRUE  ) ) {
	      if ((mu_x) < (mu_y)) {
		if ( ( TRUE  ) )
		  return;
		else
		  what_rule++;
	      }
	      else
		what_rule += 1;
	}
	else
	  what_rule += 1;
    r = what_rule - 0;
    }
  }

  void Code(unsigned r)
  {
if (mu_y.isundefined())
  mu_temp.undefine();
else
  mu_temp = mu_y;
if (mu_x.isundefined())
  mu_y.undefine();
else
  mu_y = mu_x;
if (mu_temp.isundefined())
  mu_x.undefine();
else
  mu_x = mu_temp;
mu_commonDivdors ( mu_x, mu_y, mu_arr_xy );
  };

};
/******************** RuleBase1 ********************/
class RuleBase1
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    return tsprintf("Rule 0");
  }
  bool Condition(unsigned r)
  {
    return (mu_r) > (0);
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 1;
    while (what_rule < 2 )
      {
	if ( ( TRUE  ) ) {
	      if ((mu_r) > (0)) {
		if ( ( TRUE  ) )
		  return;
		else
		  what_rule++;
	      }
	      else
		what_rule += 1;
	}
	else
	  what_rule += 1;
    r = what_rule - 1;
    }
  }

  void Code(unsigned r)
  {
mu_gcd ( mu_x, mu_y, mu_r );
  };

};
class NextStateGenerator
{
  RuleBase0 R0;
  RuleBase1 R1;
public:
void SetNextEnabledRule(unsigned & what_rule)
{
  category = CONDITION;
  if (what_rule<1)
    { R0.NextRule(what_rule);
      if (what_rule<1) return; }
  if (what_rule>=1 && what_rule<2)
    { R1.NextRule(what_rule);
      if (what_rule<2) return; }
}
bool Condition(unsigned r)
{
  category = CONDITION;
  if (r<=0) return R0.Condition(r-0);
  if (r>=1 && r<=1) return R1.Condition(r-1);
Error.Notrace("Internal: NextStateGenerator -- checking condition for nonexisting rule.");
return 0;}
void Code(unsigned r)
{
  if (r<=0) { R0.Code(r-0); return; } 
  if (r>=1 && r<=1) { R1.Code(r-1); return; } 
}
int Priority(unsigned short r)
{
  if (r<=0) { return R0.Priority(); } 
  if (r>=1 && r<=1) { return R1.Priority(); } 
return 0;}
char * Name(unsigned r)
{
  if (r<=0) return R0.Name(r-0);
  if (r>=1 && r<=1) return R1.Name(r-1);
  return NULL;
}
};
const unsigned numrules = 2;

/********************
  parameter
 ********************/
#define RULES_IN_WORLD 2


/********************
  Startstate records
 ********************/
/******************** StartStateBase0 ********************/
class StartStateBase0
{
public:
  char * Name(unsigned short r)
  {
    return tsprintf("Startstate 0");
  }
  void Code(unsigned short r)
  {
mu_x = 12;
mu_y = 16;
mu_r = (mu_x) % (mu_y);
mu_commonDivdors ( 12, 16, mu_arr_1 );
mu_commonDivdors ( 12, 16, mu_arr_xy );
  };

};
class StartStateGenerator
{
  StartStateBase0 S0;
public:
void Code(unsigned short r)
{
  if (r<=0) { S0.Code(r-0); return; }
}
char * Name(unsigned short r)
{
  if (r<=0) return S0.Name(r-0);
  return NULL;
}
};
const rulerec startstates[] = {
{ NULL, NULL, NULL, FALSE},
};
unsigned short StartStateManager::numstartstates = 1;

/********************
  Invariant records
 ********************/
int mu__invariant_6() // Invariant "commonDivdors"
{
return mu_compare( mu_arr_1, mu_arr_xy );
};

bool mu__condition_7() // Condition for Rule "commonDivdors"
{
  return mu__invariant_6( );
}

/**** end rule declaration ****/

const rulerec invariants[] = {
{"commonDivdors", &mu__condition_7, NULL, },
};
const unsigned short numinvariants = 1;

/********************
  Normal/Canonicalization for scalarset
 ********************/
/*
arr_1:NoScalarset
temp:NoScalarset
y:NoScalarset
x:NoScalarset
r:NoScalarset
arr_i:NoScalarset
arr_xy:NoScalarset
*/

/********************
Code for symmetry
 ********************/

/********************
 Permutation Set Class
 ********************/
class PermSet
{
public:
  // book keeping
  enum PresentationType {Simple, Explicit};
  PresentationType Presentation;

  void ResetToSimple();
  void ResetToExplicit();
  void SimpleToExplicit();
  void SimpleToOne();
  bool NextPermutation();

  void Print_in_size()
  { int ret=0; for (int i=0; i<count; i++) if (in[i]) ret++; cout << "in_size:" << ret << "\n"; }


  /********************
   Simple and efficient representation
   ********************/
  bool AlreadyOnlyOneRemain;
  bool MoreThanOneRemain();


  /********************
   Explicit representation
  ********************/
  unsigned long size;
  unsigned long count;
  // in will be of product of factorial sizes for fast canonicalize
  // in will be of size 1 for reduced local memory canonicalize
  bool * in;

  // auxiliary for explicit representation

  // in/perm/revperm will be of factorial size for fast canonicalize
  // they will be of size 1 for reduced local memory canonicalize
  // second range will be size of the scalarset
  // procedure for explicit representation
  // General procedure
  PermSet();
  bool In(int i) const { return in[i]; };
  void Add(int i) { for (int j=0; j<i; j++) in[j] = FALSE;};
  void Remove(int i) { in[i] = FALSE; };
};
bool PermSet::MoreThanOneRemain()
{
  int i,j;
  if (AlreadyOnlyOneRemain)
    return FALSE;
  else {
  }
  AlreadyOnlyOneRemain = TRUE;
  return FALSE;
}
PermSet::PermSet()
: Presentation(Simple)
{
  int i,j,k;
  if (  args->sym_alg.mode == argsym_alg::Exhaustive_Fast_Canonicalize) {

  /********************
   declaration of class variables
  ********************/
  in = new bool[1];

    // Set perm and revperm

    // setting up combination of permutations
    // for different scalarset
    int carry;
    size = 1;
    count = 1;
    for (i=0; i<1; i++)
      {
        carry = 1;
        in[i]= TRUE;
    }
  }
  else
  {

  /********************
   declaration of class variables
  ********************/
  in = new bool[1];
  in[0] = TRUE;
  }
}
void PermSet::ResetToSimple()
{
  int i;

  AlreadyOnlyOneRemain = FALSE;
  Presentation = Simple;
}
void PermSet::ResetToExplicit()
{
  for (int i=0; i<1; i++) in[i] = TRUE;
  Presentation = Explicit;
}
void PermSet::SimpleToExplicit()
{
  int i,j,k;
  int start, class_size;

  // Setup range for mapping

  // To be In or not to be

  // setup explicit representation 
  // Set perm and revperm
  for (i=0; i<1; i++)
    {
      in[i] = TRUE;
    }
  Presentation = Explicit;
  if (args->test_parameter1.value==0) Print_in_size();
}
void PermSet::SimpleToOne()
{
  int i,j,k;
  int class_size;
  int start;


  // Setup range for mapping
  Presentation = Explicit;
}
bool PermSet::NextPermutation()
{
  bool nexted = FALSE;
  int start, end; 
  int class_size;
  int temp;
  int j,k;

  // algorithm
  // for each class
  //   if forall in the same class reverse_sorted, 
  //     { sort again; goto next class }
  //   else
  //     {
  //       nexted = TRUE;
  //       for (j from l to r)
  // 	       if (for all j+ are reversed sorted)
  // 	         {
  // 	           swap j, j+1
  // 	           sort all j+ again
  // 	           break;
  // 	         }
  //     }
if (!nexted) return FALSE;
  return TRUE;
}

/********************
 Symmetry Class
 ********************/
class SymmetryClass
{
  PermSet Perm;
  bool BestInitialized;
  state BestPermutedState;

  // utilities
  void SetBestResult(int i, state* temp);
  void ResetBestResult() {BestInitialized = FALSE;};

public:
  // initializer
  SymmetryClass() : Perm(), BestInitialized(FALSE) {};
  ~SymmetryClass() {};

  void Normalize(state* s);

  void Exhaustive_Fast_Canonicalize(state *s);
  void Heuristic_Fast_Canonicalize(state *s);
  void Heuristic_Small_Mem_Canonicalize(state *s);
  void Heuristic_Fast_Normalize(state *s);

  void MultisetSort(state* s);
};


/********************
 Symmetry Class Members
 ********************/
void SymmetryClass::MultisetSort(state* s)
{
        mu_arr_1.MultisetSort();
        mu_temp.MultisetSort();
        mu_y.MultisetSort();
        mu_x.MultisetSort();
        mu_r.MultisetSort();
        mu_arr_i.MultisetSort();
        mu_arr_xy.MultisetSort();
}
void SymmetryClass::Normalize(state* s)
{
  switch (args->sym_alg.mode) {
  case argsym_alg::Exhaustive_Fast_Canonicalize:
    Exhaustive_Fast_Canonicalize(s);
    break;
  case argsym_alg::Heuristic_Fast_Canonicalize:
    Heuristic_Fast_Canonicalize(s);
    break;
  case argsym_alg::Heuristic_Small_Mem_Canonicalize:
    Heuristic_Small_Mem_Canonicalize(s);
    break;
  case argsym_alg::Heuristic_Fast_Normalize:
    Heuristic_Fast_Normalize(s);
    break;
  default:
    Heuristic_Fast_Canonicalize(s);
  }
}

/********************
 Permute and Canonicalize function for different types
 ********************/
void mu_1_val_t::Permute(PermSet& Perm, int i) {};
void mu_1_val_t::SimpleCanonicalize(PermSet& Perm) {};
void mu_1_val_t::Canonicalize(PermSet& Perm) {};
void mu_1_val_t::SimpleLimit(PermSet& Perm) {};
void mu_1_val_t::ArrayLimit(PermSet& Perm) {};
void mu_1_val_t::Limit(PermSet& Perm) {};
void mu_1_val_t::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu_1_arr_t::Permute(PermSet& Perm, int i)
{
  static mu_1_arr_t temp("Permute_mu_1_arr_t",-1);
  int j;
  for (j=0; j<17; j++)
    array[j].Permute(Perm, i);
};
void mu_1_arr_t::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Scalarset Array\n"); };
void mu_1_arr_t::Canonicalize(PermSet& Perm){};
void mu_1_arr_t::SimpleLimit(PermSet& Perm){}
void mu_1_arr_t::ArrayLimit(PermSet& Perm) {}
void mu_1_arr_t::Limit(PermSet& Perm){}
void mu_1_arr_t::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
void mu_1_cmp_type::Permute(PermSet& Perm, int i)
{
};
void mu_1_cmp_type::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Record with no scalarset variable\n"); };
void mu_1_cmp_type::Canonicalize(PermSet& Perm)
{
};
void mu_1_cmp_type::SimpleLimit(PermSet& Perm){}
void mu_1_cmp_type::ArrayLimit(PermSet& Perm){}
void mu_1_cmp_type::Limit(PermSet& Perm)
{
};
void mu_1_cmp_type::MultisetLimit(PermSet& Perm)
{
};

/********************
 Auxiliary function for error trace printing
 ********************/
bool match(state* ns, StatePtr p)
{
  int i;
  static PermSet Perm;
  static state temp;
  StateCopy(&temp, ns);
  if (args->symmetry_reduction.value)
    {
      if (  args->sym_alg.mode == argsym_alg::Exhaustive_Fast_Canonicalize) {
        Perm.ResetToExplicit();
        for (i=0; i<Perm.count; i++)
          if (Perm.In(i))
            {
              if (ns != workingstate)
                  StateCopy(workingstate, ns);
              
              mu_arr_1.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_arr_1.MultisetSort();
              mu_temp.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_temp.MultisetSort();
              mu_y.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_y.MultisetSort();
              mu_x.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_x.MultisetSort();
              mu_r.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_r.MultisetSort();
              mu_arr_i.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_arr_i.MultisetSort();
              mu_arr_xy.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_arr_xy.MultisetSort();
            if (p.compare(workingstate)) {
              StateCopy(workingstate,&temp); return TRUE; }
          }
        StateCopy(workingstate,&temp);
        return FALSE;
      }
      else {
        Perm.ResetToSimple();
        Perm.SimpleToOne();
        if (ns != workingstate)
          StateCopy(workingstate, ns);

          mu_arr_1.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_arr_1.MultisetSort();
          mu_temp.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_temp.MultisetSort();
          mu_y.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_y.MultisetSort();
          mu_x.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_x.MultisetSort();
          mu_r.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_r.MultisetSort();
          mu_arr_i.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_arr_i.MultisetSort();
          mu_arr_xy.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_arr_xy.MultisetSort();
        if (p.compare(workingstate)) {
          StateCopy(workingstate,&temp); return TRUE; }

        while (Perm.NextPermutation())
          {
            if (ns != workingstate)
              StateCopy(workingstate, ns);
              
              mu_arr_1.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_arr_1.MultisetSort();
              mu_temp.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_temp.MultisetSort();
              mu_y.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_y.MultisetSort();
              mu_x.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_x.MultisetSort();
              mu_r.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_r.MultisetSort();
              mu_arr_i.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_arr_i.MultisetSort();
              mu_arr_xy.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_arr_xy.MultisetSort();
            if (p.compare(workingstate)) {
              StateCopy(workingstate,&temp); return TRUE; }
          }
        StateCopy(workingstate,&temp);
        return FALSE;
      }
    }
  if (!args->symmetry_reduction.value
      && args->multiset_reduction.value)
    {
      if (ns != workingstate)
          StateCopy(workingstate, ns);
      mu_arr_1.MultisetSort();
      mu_temp.MultisetSort();
      mu_y.MultisetSort();
      mu_x.MultisetSort();
      mu_r.MultisetSort();
      mu_arr_i.MultisetSort();
      mu_arr_xy.MultisetSort();
      if (p.compare(workingstate)) {
        StateCopy(workingstate,&temp); return TRUE; }
      StateCopy(workingstate,&temp);
      return FALSE;
    }
  return (p.compare(ns));
}

/********************
 Canonicalization by fast exhaustive generation of
 all permutations
 ********************/
void SymmetryClass::Exhaustive_Fast_Canonicalize(state* s)
{
  int i;
  static state temp;
  Perm.ResetToExplicit();

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_arr_1.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_arr_1.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_temp.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_temp.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_y.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_y.MultisetSort();
        SetBestResult(i, workingstate);
      }
 