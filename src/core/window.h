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
#ifndef CORE_WINDOW_H
#define CORE_WINDOW_H

#include "io/logger.h"

#include <GLFW/glfw3.h>
#include <string>

class window
{
public:
	static window &instance()
	{
		static window w;
		return w;
	}

	~window();

	/* Is GLFW window open */
	const bool &is_glfw_window_open() const
	{
		return _glfw_window_open;
	}

	/* Window width */
	const int &width() const
	{
		return _width;
	}

	/* Window heigth */
	const int &height() const
	{
		return _height;
	}

	/* Window name */
	const std::string &name() const
	{
		return _name;
	}

	/* Window set size */
	void set_window_size(int const &width, int const &height);

	/* Resize window */
	void resize();

	/* Is window should close? */
	const bool &is_close() const
	{
		return _close;
	}

	/* Close the window */
	void close();

	/* Window main loop */
	void loop();

private:
	window();
	window(window const &) = delete;
	window &operator=(window const &) = delete;

	/* GLFW window */
	GLFWwindow *_glfw_window;

	/* Is GLFW window open? */
	bool _glfw_window_open = false;

	/* Window width */
	int _width = 640;

	/* Window heigth */
	int _height = 480;

	/* Window name */
	std::string _name = "Lanthe";

	/* Set window width */
	void _set_width(int const &width);

	/* Set window height */
	void _set_height(int const &height);

	/* Initialize the GLFW library */
	void _initialize_glfw();

	/* Greate GLFW window */
	void _create_glfw_window();

	/* Are we should close the window? */
	bool _close = false;
};

#endif // CORE_WINDOW_H