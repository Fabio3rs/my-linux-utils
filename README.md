# my-linux-utils

Backup of some utils code

chroot-this - bash script to fast chroot, incomplete

genfstab.c - source for a C program to generate fstab from mounted drivers, incomplete, not fully tested

logrotate.patch - patch for gentoo app-admin/logrotate-3.14.0 that was not compiling in my PC with folow linking error:
x86_64-pc-linux-gnu-gcc -Wall -Wextra -Wmissing-format-attribute -Wmissing-noreturn -Wpointer-arith -Wshadow -Wstrict-prototypes -Wundef -Wunused -Wwrite-strings -O2 -pipe -march=native -mtune=native -s -fno-common -Wl,-O1 -Wl,--as-needed  -Wl,-O1 -Wl,--as-needed -o logrotate config.o log.o logrotate.o  -lacl -lpopt 
/usr/lib/gcc/x86_64-pc-linux-gnu/10.2.0/../../../../x86_64-pc-linux-gnu/bin/ld: logrotate.o:(.bss+0x10): multiple definition of `logs'; config.o:(.bss+0x0): first defined here
collect2: error: ld returned 1 exit status
make[2]: *** [Makefile:493: logrotate] Error 1
make[2]: Leaving directory '/var/tmp/portage/app-admin/logrotate-3.14.0/work/logrotate-3.14.0'
make[1]: *** [Makefile:612: all-recursive] Error 1
make[1]: Leaving directory '/var/tmp/portage/app-admin/logrotate-3.14.0/work/logrotate-3.14.0'
make: *** [Makefile:392: all] Error 2
 * ERROR: app-admin/logrotate-3.14.0::gentoo failed (compile phase):
 *   emake failed
 * 


THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
