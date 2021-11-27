#define CITY_LENGTH 30
#define STREET_LENGTH 50
typedef struct _Address
{
  char City[CITY_LENGTH];
  char Street[STREET_LENGTH];
  int BuildingNo;
} Address;

bool ReadTextAddress(const char*, Address*);
bool WriteTextAddress(const char*, const Address*);
bool ReadBinaryAddress(const char*, Address*);
bool WriteBinaryAddress(const char*, const Address*);
