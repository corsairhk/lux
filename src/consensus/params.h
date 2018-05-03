// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2014 The Bitcoin Core developers
// Copyright (c) 2017-2018 The Luxcore developers

#ifndef BITCOIN_CONSENSUS_PARAMS_H
#define BITCOIN_CONSENSUS_PARAMS_H

#include "uint256.h"

namespace Consensus {

    enum DeploymentPos
    {
        DEPLOYMENT_TESTDUMMY,
        DEPLOYMENT_CSV, // Deployment of BIP68, BIP112, and BIP113.
        DEPLOYMENT_SEGWIT, // Deployment of BIP141 and BIP143
        // NOTE: Also add new deployments to VersionBitsDeploymentInfo in versionbits.cpp
        MAX_VERSION_BITS_DEPLOYMENTS
    };

    /**
     * Struct for each individual consensus rule change using BIP9.
     */
    struct BIP9Deployment {
        /** Bit position to select the particular bit in nVersion. */
        int bit;
        /** Start MedianTime for version bits miner confirmation. Can be a date in the past */
        int64_t nStartTime;
        /** Timeout/expiry MedianTime for the deployment attempt. */
        int64_t nTimeout;
    };

    /**
     * Parameters that influence chain consensus.
     */
    struct Params {
        uint256 hashGenesisBlock;
        int nSubsidyHalvingInterval;
        /** Used to check majorities for block version upgrade */
        int nEnforceBlockUpgradeMajority;
        int nRejectBlockOutdatedMajority;
        int nToCheckBlockUpgradeMajority;
        /** Proof of work parameters */
        int nLastPOWBlock;
        int64_t nTargetSpacing;
        int64_t nTargetTimespan;
        /** Proof of stake parameters */
        int64_t nStakingRoundPeriod;
        int64_t nStakingInterval;
        int64_t nStakingMinAge;
    };
} // namespace Consensus

#endif // BITCOIN_CONSENSUS_PARAMS_H
