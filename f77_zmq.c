#include "zmq.h"

void* f77_zmq_ctx_new_ ()
{
    return zmq_ctx_new ();
}

int f77_zmq_ctx_destroy_ (void* *context)
{
    return zmq_ctx_destroy (*context);
}

int f77_zmq_ctx_set_ (void* *context, int* option_name, int* option_value)
{
  return zmq_ctx_set (*context, *option_name, *option_value);
}


void* f77_zmq_socket_ (void* *context, int* type)
{
    return zmq_socket (*context, *type);
}

int f77_zmq_close_ (void* *socket)
{
    return zmq_close(*socket);
}

int f77_zmq_bind_ (void* *socket, char* address_in, int address_len)
{
  char address[address_len+1];
  int i;
  for (i=0 ; i<address_len ; i++)
  {
    address[i] = address_in[i];
  }
  address[address_len] = 0;
  return zmq_bind (*socket, address);
}

int f77_zmq_connect_ (void* *socket, char* address_in, int address_len)
{
  char address[address_len+1];
  int i;
  for (i=0 ; i<address_len ; i++)
  {
    address[i] = address_in[i];
  }
  address[address_len] = 0;
  return zmq_connect (*socket, address);
}

int f77_zmq_setsockopt_ (void* *socket, int* option_name, void* option_value, int* option_len, int dummy)
{
  return zmq_setsockopt (*socket, *option_name, option_value, *option_len);
}

int f77_zmq_getsockopt_ (void* *socket, int* option_name, void *option_value, int *option_len, int dummy)
{
  size_t option_len_st = *option_len;
  return zmq_getsockopt (*socket, *option_name, option_value, &option_len_st);
  *option_len = option_len_st;
}



int f77_zmq_send_ (void* *socket, void* message, int* message_len, int* flags, int dummy)
{
  return zmq_send (*socket, message, *message_len, *flags);
}

int f77_zmq_recv_ (void* *socket, void* message, int* message_len, int* flags, int dummy)
{
  return zmq_recv (*socket, message, *message_len, *flags);
}


