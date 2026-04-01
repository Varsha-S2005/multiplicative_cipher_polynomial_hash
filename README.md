# Multiplicative Cipher & Hybrid FNV-Polynomial Hash (C++)

This project implements a secure communication simulation featuring a **Multiplicative Cipher** for encryption/decryption and a **Hybrid Hash Function** that combines **FNV-1a hashing with Polynomial Rolling techniques** for data integrity verification.

---

## 1. Deliverables
- Encryption/Decryption using Multiplicative Cipher  
- Hybrid FNV + Polynomial Hash for integrity verification  
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

### Hybrid FNV-Polynomial Hash

This project uses a **customized hashing approach** combining:

- **FNV-1a Hash** → strong bit mixing (XOR + multiplication)  
- **Polynomial Rolling Hash** → position-based weighting  

#### Working:

1. Each character is converted to a numeric value  
2. A polynomial weight is applied using powers of base (p = 31)  
3. The result is mixed into the hash using FNV-1a operations:

   H = (H XOR (value × p^i)) × FNV_prime  

4. A finalization step is applied for extra bit mixing  

---

### Constants Used
- FNV Offset Basis: 1469598103934665603  
- FNV Prime: 1099511628211  
- Polynomial Base (p): 31  

---

## 3. Justification for Hash technique used:

- Combines **order sensitivity** (polynomial)  
- Adds **strong distribution** (FNV)  
- Reduces collision probability  
- Key-dependent initialization improves uniqueness  
- More robust than using FNV or polynomial alone  

---

## 4. How to Run

### Compile
```bash
g++ -o multiplicative_cipher main.cpp
```

### Run
```bash
./mustiplicative_cipher
```

---

## 5. Input

- Enter your message  
- Enter a valid key (coprime with 26):  
  3, 5, 7, 11, 15, 17, 19, 21, 23, 25  

---

## 6. Output Examples

### Example 1
```
Enter the message: cryptography cia
Enter the key: 5

Ciphertext:        khqxrsehaxjq koa
Decrypted Message: cryptography cia

Original Hash:     1130028036166253770
Final Hash:        1130028036166253770

STATUS: SUCCESS
```

---

### Example 2
```
Enter the message: Multiplicative Cipher
Enter the key: 3

Ciphertext:        Kihfythygafylm Gytvmz
Decrypted Message: Multiplicative Cipher

Original Hash:     8835463411036666952
Final Hash:        8835463411036666952

STATUS: SUCCESS
```

---

## 7. Features

- Hybrid FNV + Polynomial hashing  
- Key-dependent hash initialization  
- Finalization step for better bit mixing  
- Supports uppercase and lowercase  
- Preserves spaces and special characters  
- Efficient and fast execution  

---

## 8. Summary

This project enhances a classical **Multiplicative Cipher** by integrating a **modern hybrid hashing technique** that combines:

- FNV-1a (bit-level mixing)  
- Polynomial hashing (position sensitivity)  

This results in a more reliable and collision-resistant integrity verification system.
