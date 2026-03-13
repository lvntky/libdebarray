#include <debarray.h>
#include <stdio.h>

static const char *get_type_identifier(deb_type_t type)
{
	switch (type) {
	case DEB_INT: {
		return "%d";
		break;
	}
	default:
		return "%d";
		break;
	}
}

void deb_print(const void *arr, size_t len, deb_type_t type)
{
	char *type_identifier = get_type_identifier(type);
	printf("type: %s\n", type_identifier);
}
