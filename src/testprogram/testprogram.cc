/* SPDX-License-Identifier: LGPL-3.0-or-later */

/*
 * Copyright (C) 2021 Perry Werneck <perry.werneck@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

 #include <config.h>

 #include <udjat/tools/systemservice.h>
 #include <udjat/tools/application.h>
 #include <udjat/tools/url.h>
 #include <udjat/tools/http.h>
 #include <udjat/agent.h>
 #include <udjat/factory.h>
 #include <udjat/module.h>
 #include <iostream>
 #include <memory>

 using namespace std;
 using namespace Udjat;

//---[ Implement ]------------------------------------------------------------------------------------------

int main(int argc, char **argv) {

	/*
	if(HTTP::Client("http://127.0.0.1/~perry/test.xml").get("/tmp/localhost.html")) {
		cout << endl << endl << "File was updated!" << endl << endl;
	}
	*/

	udjat_module_init();

	//cout << "Response:" << endl << URL("http://localhost").get() << endl;

	/*
	if(URL("http://127.0.0.1/~perry/test.xml").get("localhost.html")) {
		cout << endl << endl << "File was updated!" << endl << endl;
	}
	*/

	URL("http://localhost").get("/tmp/localhost.html",[](double current, double total){
		cout << "Donwloading " << current << " of " << total << endl;
		return true;
	});

	Udjat::Module::unload();

	return 0;

}
