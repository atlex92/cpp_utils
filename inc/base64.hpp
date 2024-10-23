/*
 * Copyright (c) 2013 Adam Rudd.
 * See LICENSE for more information
 */
#pragma once
unsigned int base64_encode(char* output, const char* input, unsigned int inputLen);
unsigned int base64_decode(char* output, const char* input, unsigned int inputLen);
unsigned int base64_enc_len(const unsigned int inputLen);
unsigned int base64_dec_len(const char* input, const unsigned int inputLen);