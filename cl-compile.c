/*
 * Copyright (c) 2016 Andrej Hoos
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

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
