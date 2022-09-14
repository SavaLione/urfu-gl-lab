/*
 * SPDX-License-Identifier: BSD-3-Clause
 * 
 * Copyright (c) 2022, Saveliy Pototskiy (SavaLione) (savalione.com)
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the copyright holder nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */
/**
 * @file
 * @brief Lanthe application window
 * @author Saveliy Pototskiy (SavaLione)
 * @date 10 Sep 2022
 */
#include "core/window.h"

#include "spdlog/spdlog.h"

window::window()
{
	spdlog::info("Creating glfw window.");

	_initialize_glfw();

	_create_glfw_window();

	/* Make the window's context current */
	glfwMakeContextCurrent(_glfw_window);
}

window::~window()
{
	spdlog::info("Destroying glfw window.");

	if(is_glfw_window_open())
	{
	}

	glfwTerminate();
}

void window::set_window_size(int const &width, int const &height)
{
	_set_width(width);
	_set_height(height);
}

void window::_set_width(int const &width)
{
	_width = width;
}

void window::_set_height(int const &height)
{
	_height = height;
}

void window::resize()
{
	if(is_glfw_window_open())
	{
		glfwSetWindowSize(_glfw_window, width(), height());
	}
}

void window::_initialize_glfw()
{
	/* Initialize the GLFW library */
	if(!glfwInit())
	{
		// Cannot create GLFW window
		spdlog::error("Cannot create GLFW window (the GLFW library initialization error)");
		_glfw_window_open = false;
	}
	else
	{
		// GLFW window created
		_glfw_window_open = true;
	}
}

void window::_create_glfw_window()
{
	/* Create a windowed mode window and its OpenGL context */
	_glfw_window = glfwCreateWindow(width(), height(), name().c_str(), NULL, NULL);

	if(!_glfw_window)
	{
		// Cannot create GLFW window
		spdlog::error("Cannot create GLFW window (the GLFW library creating windowed mode error)");
		_glfw_window_open = false;
	}
	else
	{
		// GLFW window created
		_glfw_window_open = true;
	}
}

void window::close()
{
	_close = true;
}

void window::loop()
{
	// Do we need to close the window?
	if(glfwWindowShouldClose(_glfw_window))
    {
        close();
    }

	/* Render here */
	glClear(GL_COLOR_BUFFER_BIT);

	/* Swap front and back buffers */
	glfwSwapBuffers(_glfw_window);

	/* Poll for and process events */
	glfwPollEvents();
}