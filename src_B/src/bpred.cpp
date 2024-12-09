// --------------------------------------------------------------------- //
// For part B, you will need to modify this file.                        //
// You may add any code you need, as long as you correctly implement the //
// three required BPred methods already listed in this file.             //
// --------------------------------------------------------------------- //

// bpred.cpp
// Implements the branch predictor class.

#include "bpred.h"

/**
 * Construct a branch predictor with the given policy.
 * 
 * In part B of the lab, you must implement this constructor.
 * 
 * @param policy the policy this branch predictor should use
 */
BPred::BPred(BPredPolicy policy)
{
    // TODO: Initialize member variables here.

    // As a reminder, you can declare any additional member variables you need
    // in the BPred class in bpred.h and initialize them here.


 this->policy = (BPredPolicy) policy;
 this->stat_num_branches = 0;
 this->stat_num_mispred = 0;
 uint32_t i;
 for (i=0; i<PHT_SIZE; i++)
 {
  this->pht[i] = 2;
 }
 this->bht = 0;


}



/**
 * Get a prediction for the branch with the given address.
 * 
 * In part B of the lab, you must implement this method.
 * 
 * @param pc the address (program counter) of the branch to predict
 * @return the prediction for whether the branch is taken or not taken
 */
BranchDirection BPred::predict(uint64_t pc)
{
    // TODO: Return a prediction for whether the branch at address pc will be
    // TAKEN or NOT_TAKEN according to this branch predictor's policy.

    // Note that you do not have to handle the BPRED_PERFECT policy here; this
    // function will not be called for that policy.

//    return TAKEN; // This is just a placeholder.

// uint32_t pc1,bht1;
 if (this->policy == BPRED_ALWAYS_TAKEN)
 {
  return TAKEN;
 }
 else if (this->policy == BPRED_GSHARE)
 {
  //bht1 = this->bht & 4095;
  //pc1 = pc & 4095;
  uint32_t address = (pc ^ this->bht) & 4095;
  // BranchDirection x = p->b_pred->predict(fetch_op->trace.rec.inst_addr);
  //  addr = BranchDirection(BPredPolicy);
  // return this->pht[address] >= 2;
  if (this->pht[address] >= 2)
  {
   return TAKEN;
  }
  //BranchDirection x = p->b_pred->predict(fetch_op->trace_rec.inst_addr);
  //return this->pht[x] >= 2;
  else
  {
   return NOT_TAKEN;
  }
 }
 return NOT_TAKEN;
}




/**
 * Update the branch predictor statistics (stat_num_branches and
 * stat_num_mispred), as well as any other internal state you may need to
 * update in the branch predictor.
 * 
 * In part B of the lab, you must implement this method.
 * 
 * @param pc the address (program counter) of the branch
 * @param prediction the prediction made by the branch predictor
 * @param resolution the actual outcome of the branch
 */
void BPred::update(uint64_t pc, BranchDirection prediction,
                   BranchDirection resolution)
{
    // TODO: Update the stat_num_branches and stat_num_mispred member variables
    // according to the prediction and resolution of the branch.

    // TODO: Update any other internal state you may need to keep track of.

    // Note that you do not have to handle the BPRED_PERFECT policy here; this
    // function will not be called for that policy.


 uint32_t address = (pc ^ this->bht) & 4095;
 this->bht = (this->bht << 1) | resolution;
 if (resolution)
 {
  this->pht[address]= (this->pht[address] == 3) ? 3 : (this->pht[address] + 1);
 }
 else
 {
  this->pht[address] = (this->pht[address] == 0) ? 0 : (this->pht[address] - 1);
 }


}


