#include "cl-helper.h"

int main(int argc, char **argv) {
	if (argc < 3) {
	    fprintf(stderr, "need at least two arguments!\n");
	    abort();
	}

	cl_context ctx;
  	cl_command_queue queue;

	char const *platform;
	char const *device;
  	if(argc > 3){
  		platform = argv[3];
  	}else{
  		platform = CHOOSE_INTERACTIVELY;
  	}
  	if(argc > 4){
  		device = argv[4];
  	}else{
  		device = CHOOSE_INTERACTIVELY;
  	}
  	
  	create_context_on(platform, device, 0, &ctx, &queue, 0);

  	char *knl_text = read_file(argv[1]);

  	cl_program program = program_from_string(ctx, knl_text, NULL);

  	save_program_binaries(ctx, program, argv[2]);
}
