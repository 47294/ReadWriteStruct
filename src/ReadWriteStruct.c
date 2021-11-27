#include <stdbool.h>
#include <stdio.h>
#include "../includes/Head.h"

bool WriteBinaryAddress(const char* filename, const Address* address)
{
  FILE* fout = fopen(filename, "wb");
  
  if (fout == NULL)
    return false;
  
  int writed = fwrite(address, sizeof(Address), 1, fout);
  //fwrite(address, 1, sizeof(Address), fout);
  
  fclose(fout);
  
  return writed == 1;
}

bool ReadBinaryAddress(const char* filename, Address* address)
{
  FILE* fin = fopen(filename, "rb");
  
  if (fin == NULL)
    return false;
  
  fseek(fin, 0, SEEK_END);
  int fileSize = ftell(fin);
  rewind(fin); //   fseek(fin, 0, SEEK_SET);
  
  if(fileSize != sizeof(Address)) {
    fclose(fin);
    return false;
  }
  
  int readed = fread(address, sizeof(Address), 1, fin);
  
  fclose(fin);
  
  return readed == 1;
}

bool WriteTextAddress(const char* filename, const Address* address)
{
  FILE* fout = fopen(filename, "wt");
  
  if(fout == NULL)
    return false;
    
  fprintf(fout, "%s|%s|%d", address->City, address->Street, address->BuildingNo);
  
  fclose(fout);
  
  return true;
}

bool ReadTextAddress(const char* filename, Address* address)
{
  FILE* fin = fopen(filename, "rt");
  
  if(fin == NULL)
    return false;
    
  fscanf(fin, "%[^|]s", address->City);
  fscanf(fin, "%*c%[^|]s", address->Street);
  fscanf(fin, "%*c%d", &address->BuildingNo);
  
  fclose(fin);
  
  return true;
}


