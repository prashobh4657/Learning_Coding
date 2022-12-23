
/*
 input : n
  let n=2
  print all generate balanced parenthesis
  1. ()()
  2. (())
  means we have 4 boxes now we need to put (, (, ), ), in those 4 boxes
  in such a way finally that should be balancedk
  hence here only two ways : 1. ()() 2. (())


 n=3
 1. ((()))
 2. (()())
 3. (())()
 4. ()(())
 5. ()()()
 These all should be stored in vector of string and then return.

 Recursion identification:
  1. in question it is mentioned solve by recursion
  2. recursively defined question --> kth grammar
  3. like in DS : trees, etc.
  4. Some question we need to see choices + decision  --> recursive tree



  Now n=3
  3 open , 3 close brackets
  [][][][][][]  (6 boxes) (we need to fill such that it is balanced)

  Now for each box we have 2 choices , either we can fill it by open bracket or close bracket.
  Now we need to take decision such that final ans should be balanced.

  Let's make recursive tree
   IP - OP method (extended)
   1. Here data-type of IP and OP will not same.
   2. here IP=n (integer) and OP = string

   n=3
   [][][][][][] (6 boxes) (3 open and 3 bracket)
   Here open =3 and close =3 (here two variables which will keep track of count of open and close brackets which we have included till now)

   n=3, IP (O=3,C=3) and OP=""(empty)
   Here
    in starting we can't use closing bracket as that will not make final answer = balanced
    hence in starting we need to include Open bracket
    in short , first box has to be fill by open bracket.

    Now O=O-1=3-1 =2
    Now next time (for 2nd box) we have two choices
    either we can use again open bracket
    or using close bracket .



      This below tree is not complete
      see its image (for recursive tree)
            op="", O=3,C=3
                 |    (only 1 choice, take open bracket)
          "(" o=2,c=3
              /                         \
   op="((" o=1,c=3                     "()", o=2,c=2
          /      \                        | (here only 1choice only to use open)
  op="((("      op="(("+")"="(()"         op="()("
  o=0, c=3       o=1,c=2                 op=1,c=2
   |                 /\                    /\
"((()" o=0,c=2      z1 z2                 z3 z4
  |                 o=1   o=1          "()(("   "()()"
"((())" o=0,c=1     c=2   c=1            o=0       |
  |                "(()("  "(())"        c=2      here only open
"((()))"o=0,c=0              |           hereo=0   |
                            "(())("
                             |
                           "(())()"
  now here
  when open
  finished
  then apply
  all close
  one by one
  once o=0,c=0
  then we have to stop
  and OP is our final
  string.




Here we use some observation skills
here sometimes we draw 2 branches , sometimes we draw 1 branch
Sometimes we have closing bracket wali branch adn sometimes it is not there
opening bracket is always there till O=0
Now let's figure out what is the condition when we get choice for closing bracket choice
 Here we get obeserved that when O<C then we will get choice of closing bracket also
 (why is this happening ? this is happenening because if we have close > open means
  no. of close brackets remaining are more than no. of open brackets remaining means (we have used more open and less close, as initially both are equal)
    means we have used more open brackets then only we can apply some close hence there will be we have choice of closing bracket)

    if(close>open)
    {

    }




*/
