# Multiplicative Cipher & FNV Hash (C++)

This project implements a secure communication simulation featuring a **Multiplicative Cipher** for encryption/decryption and an **FNV-1a Hash Function** for data integrity verification.

---

## 1. Deliverables
- Encryption/Decryption using Multiplicative Cipher  
- FNV-1a Hash for integrity verification  
- Round-trip validation (Encrypt → Decrypt → Verify)  
- Key validation using GCD  

---

## 2. Theory

### Multiplicative Cipher
Encryption:
C = (P × k) mod 26  

Decryption:
P = (C × k⁻¹) mod 26  

Condition:
gcd(k, 26) = 1  

---

### FNV-1a Hash

Formula:
H = (H XOR c) × P  

Constants:
- Offset: 1469598103934665603  
- Prime: 1099511628211  

---

## 3. How to Run

### Compile
```bash
g++ -o cipher_task main.cpp
```

### Run
```bash
./cipher_task
```

---

## 4. Input

- Enter your message  
- Enter a valid key (coprime with 26):  
  3, 5, 7, 11, 15, 17, 19, 21, 23, 25  

---

## 5. Output Example

Original Message:  Hello World  
Ciphertext:        Xubbe Mehbt  
Decrypted Message: Hello World  

Original Hash:     123456789  
Final Hash:        123456789  

STATUS: SUCCESS  

---

## 6. Features

- Fast FNV-1a hashing  
- Key-dependent hash  
- Supports uppercase/lowercase  
- Preserves spaces & symbols  
- Efficient execution  

