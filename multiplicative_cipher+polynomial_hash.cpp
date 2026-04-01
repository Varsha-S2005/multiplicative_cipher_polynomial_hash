#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 

using namespace std;

int gcd(int a, int b) { 
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int mod_inverse(int k) {
    k = k % 26;
    for (int x = 1; x < 26; x++) {
        if ((k * x) % 26 == 1) return x;
    }
    return -1; 
}

long long power(long long base, long long exp, long long mod) {
    long long res = 1;
    base %= mod;
    for (int i = 0; i < exp; i++) {
        res = (res * base) % mod;
    }
    return res;
}

unsigned long long finalize(unsigned long long h) {
    h ^= (h >> 16);           
    h *= 0x85ebca6b;         
    h ^= (h >> 13);          
    return h;
}

unsigned long long calculate_hash(string s, int key) {
    const int p = 31;
    const long long m = 1e9 + 9;
    unsigned long long hash_value = key; 
    
    for (int i = 0; i < s.size(); i++) {
        int val = toupper(s[i]) - 'A' + 1;
        long long p_pow = power(p, i, m);
        hash_value = (hash_value + (val * p_pow)) % m;
    }
    return finalize(hash_value);
}

// --- 3. CIPHER LOGIC ---

string encrypt(string s, int k) {
    string res = "";
    for (char c : s) {
        if (isalpha(c)) {
            char base;
            if(isupper(c)){
              base='A';
            }
            else{
              base='a';
            }
            int plain = c - base;
            int cipher = (plain * k) % 26;
            res += (char)(cipher + base); 
        } else {
            res += c; 
        }
    }
    return res;
}

string decrypt(string s, int k) {
    int inv = mod_inverse(k);
    string res = "";
    for (char c : s) {
        if (isalpha(c)) {
            char base;
            if(isupper(c)){
              base='A';
            }
            else{
              base='a';
            }
            int cipher = c - base;
            int plain = (cipher * inv) % 26;
            if (plain < 0) plain += 26; 
            res += (char)(plain + base); 
        } else {
            res += c;
        }
    }
    return res;
}


int main() {
    string s;
    int k;
    cout << "Enter the message: ";
    getline(cin, s);
    cout << "Enter the multiplicative key(prime number) (e.g., 3, 5, 7, 11): ";
    cin >> k;
  
    if (gcd(k, 26) != 1) {
        cout << "Error: Key " << k << " is not coprime to 26 hence, inverse does not exist!" << endl;
        return 1;
    }
    unsigned long long original_hash = calculate_hash(s, k);
    string encrypted_msg = encrypt(s, k);
    string decrypted_msg = decrypt(encrypted_msg, k);
    unsigned long long final_hash = calculate_hash(decrypted_msg, k);

    cout << "\nOUTPUT" << endl;
    cout << "Original Message:  " << s << endl;
    cout << "Ciphertext:        " << encrypted_msg << endl;
    cout << "Decrypted Message: " << decrypted_msg << endl;
    
    cout << "\nINTEGRITY CHECK" << endl;
    cout << "Original Hash:     " << original_hash << endl;
    cout << "Final Hash:        " << final_hash << endl;
    if (original_hash == final_hash) {
        cout << "STATUS: SUCCESS" << endl;
    } else {
        cout << "STATUS: FAILED " << endl;
    }

    return 0;
}
