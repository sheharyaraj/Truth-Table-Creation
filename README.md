# Truth-Table-Evaluation
You can get truth table of any equation in the code. It works for AND (*), OR (+) and NOT/NEGATION (~) operators. You can evaluate equations with up to 5 literals and brackets will also be evaluated based on priority. The basic working of evaluation has a pattern similar to that of postfix evaluation so we are using stack as well. The code has comments explaining job of each loop.

Basic logical working involves:
- Expression is read and a loop evaluates how many literals it has and selects size of the 2d array or table of that function.
- then values of the truth table are replaced in the equation in a separate loop
- then a postfix like noatation is made which is then further evaluated to get an answer corresponding to the values placed in the equation.

Note: Literals should be in terms of a,b,c,d,e.
