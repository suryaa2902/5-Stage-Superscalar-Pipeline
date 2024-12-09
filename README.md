# 5-Stage-Superscalar-Pipeline
 Dependency Tracking and Forwarding for a 5-stage Superscalar Pipeline with Branch Prediction
 
## Part A

Assumption: The pipeline has perfect branch prediction and does not suffer any stalls due to control flow dependencies. 

* A.1 Implement data dependency tracking and related stalls for a scalar machine (N=1). 
* A.2 Generalize the above (A.1) to an N-wide super-scalar (we will test for N=2, although your code should be general enough to work for any reasonable value of N). Note that 
for a superscalar machine, you may have data dependencies from the EX and MEM stages and older instructions in the ID stage. 
* A.3 Implement Data Forwarding (from both MEM and EX).  Note that the existence of a forwarding path does not necessarily mean that you can pass the value from a later instruction to an earlier instruction. For example, for a Load instruction, you would not have the value available until the MEM stage, so you cannot forward the value of Load from the EX stage to the ID stage for an instruction dependent on this Load instruction.
