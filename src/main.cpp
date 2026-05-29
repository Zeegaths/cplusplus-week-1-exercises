#include "main.h"

double calculate_total_reward(int blocks_mined) {    
    double result = MINING_REWARD * blocks_mined;

    // TODO: multiply blocks_mined by MINING_REWARD and return the result
    return result;
}

bool is_valid_tx_fee(double fee) {
    // TODO: return true if fee is between 0.00001 and 0.01 BTC (inclusive bounds up to you)
    if (fee >= 0.00001 && fee <= 0.01) {
        return true;
    }
    return false;
}

bool is_large_balance(double balance) {
    // TODO: return true if balance > 50.0 BTC
    if (balance > 50.0) {
        return true;
    }
    return false;
}

std::string tx_priority(int size_bytes, double fee_btc) {
    double fee_rate = fee_btc / size_bytes;
    if (fee_rate >= 0.00005) {
        return "high";
    }
    else if (fee_rate >= 0.00001) {
        return "medium";
    } 
    return "low";
    
    
    // TODO: compute fee rate (fee_btc / size_bytes) and return "high" / "medium" / "low"
    //       high   >= 0.00005
    //       medium >= 0.00001
    //       otherwise low    
}

bool is_mainnet(std::string network) {
    for (char& c : network) {
        c = std::tolower(c);
    }
    if (network == "mainnet") {
        return true;
    }
    // TODO: lowercase `network` and return true if it equals "mainnet"
    return false;
}

bool is_in_range(double value) {
    // TODO: return true iff 100 <= value <= 200
    if (value >= 100 && value <= 200) {
        return true;
    }
    return false;
}

bool is_same_wallet(const Wallet& w1, const Wallet& w2) {
    // TODO: return true iff both refs name the same object in memory (compare addresses)
    if (&w1 == &w2) {
        return true;
    }
    return false;
}

std::string normalize_address(std::string address) {
    // TODO: strip leading/trailing whitespace and lowercase the address
    for (char& c : address) {
        if (c == ' ') {
            address.erase(address.begin());
            address.erase(address.end() - 1);
        }
        c = std::tolower(c);
    }
    return address;
}

std::vector<int> add_utxo(std::vector<int> utxos, int new_utxo) {
    // TODO: append new_utxo to utxos and return the updated vector
    utxos.push_back(new_utxo);
    return utxos;
}

std::optional<std::pair<std::size_t, double>> find_high_fee(const std::vector<double>& fees) {
    // TODO: return (index, fee) of the first fee > 0.005, or std::nullopt if none
    for (std::size_t i = 0; i < fees.size(); ++i) {
        if (fees[i] > 0.005) {
            return std::make_pair(i, fees[i]);
        }
    }
    return std::nullopt;
}

std::tuple<std::string, double> get_wallet_details() {
    // TODO: return a tuple of (wallet_name, balance)    
    return std::make_tuple("Alice", 50.0);    
}

std::string get_tx_status(const std::map<std::string, std::string>& tx_pool, const std::string& txid) {
    // TODO: return tx_pool[txid] if present, else "not found"
    for (const auto& [tx1, tx2] : tx_pool) {
        if (tx1 == txid || tx2 == txid) {
            return tx_pool.at(txid);
        }
    }
    return "not found";
}

std::string unpack_wallet_info(const std::tuple<std::string, double>& wallet_info) {
    // TODO: destructure into (name, balance) and return "Wallet <name> has balance: <balance> BTC"
    const auto& [name, balance]= wallet_info;
    std::ostringstream oss;
    oss << "Wallet " << name << " has balance: " << std::fixed << std::setprecision(1) << balance << " BTC";
    return oss.str();
}

long long calculate_sats(double btc) {
    // TODO: multiply btc by BTC_TO_SATS and return as integer   
    return static_cast<long long>(btc * BTC_TO_SATS);
}

std::string generate_address(const std::string& prefix) {
    static const std::string chars = "abcdefghijklmnopqrstuvwxyz0123456789";
    std::string address= prefix;
    while (address.size() < 32)
        address += chars[rand() % chars.size()];
    return address;
    // TODO: append (32 - prefix.size()) random chars from [a-z0-9] to `prefix` and return it
    
}

std::pair<bool, std::string> validate_block_height(int height) {
    // TODO: reject if negative; reject if > 800000; otherwise valid
    if (height < 0) {
        return {false, "Block height cannot be negative"};
    }
    else if (height > 800000) {
        return {false, "Block height seems unrealistic"};
    }
    else {
        return {true, "Valid block height"};
    }   
}

std::pair<bool, std::string> validate_block_height(double height) {
    // TODO: a non-integer block height should always be rejected
    return {false, "Block height must be an integer"};
}

std::pair<bool, std::string> validate_block_height(const std::string& height) {
    // TODO: a string block height should always be rejected
    return {false, "Block height must be an integer"};
}

std::map<int, long long> halving_schedule(const std::vector<int>& blocks) {
    // TODO: base reward = 50 * BTC_TO_SATS sats, halve every 210_000 blocks
    //       return a map of {block_height: reward_in_sats}
    for (int block : blocks) {
        int halvings = block / 210000;
        long long reward = static_cast<long long>(50 * BTC_TO_SATS) >> halvings; 
        schedule [block] = reward;
    }
    return {};
}

std::optional<Utxo> find_utxo_with_min_value(const std::vector<Utxo>& utxos, long long target) {
    // TODO: among utxos with value >= target, return the one with the smallest value
    //       (std::nullopt if none qualifies)
    return std::nullopt;
}

std::map<std::string, UtxoField> create_utxo(
    const std::string& txid,
    int vout,
    const std::map<std::string, UtxoField>& extras
) {
    // TODO: build a map with {"txid": txid, "vout": vout} merged with `extras`
    return {};
}
