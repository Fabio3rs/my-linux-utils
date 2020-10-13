/*
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
#include <string.h>
#include <stdio.h>

int write_str(const char *str, FILE *f)
{
    return fwrite(str, 1, strlen(str), f);
}

// Todo command line, customizations on output
int main(int argc, char *argv[])
{
	FILE *f = fopen("/proc/mounts", "r");
	
	if (f != NULL)
	{
		char buff[4096]; // Read buffer
		
	    // Output fstab file - TODO implement command line
		/*FILE *outf = fopen("fstab", "w");
		
		if (outf == NULL)
		{
		    fprintf(stderr, "Fail to open fstab for writing!");
		    fclose(f);
		    return 1;
		}*/
		
		write_str("# Generated automatically reading /proc/mounts\n", stdout);
		write_str("# <file system>      <mount point>       <type>  <options>           <dump>  <pass>\n", stdout);
		
		while (fgets(buff, sizeof(buff), f) && !feof(f))
		{
			if (buff[0] == '/')
			{
				char *str = buff;
				char *m_dev, *m_mountpoint, *m_type, *m_options, *m_dump, *m_pass; // Mountpoint data
				
				// Parsing stage to future implementation of changing options
				int stage = 0;
				
				{
					// Rmove the newline from the buffer
					char *r = strchr(buff, '\n');
					if (r != NULL)
						*r = '\0';
				}
				
				do
				{
					char *lstr = str;
					
					str = strchr(str, ' ');
					
					if (str != NULL)
					{
						*str++ = '\0';
					}
					
					switch (stage)
					{
					case 0: // Mountpoint device. Example /dev/sda3
						m_dev = lstr;
						break;
						
					case 1: // Mountpoint path. Example /
						m_mountpoint = lstr;
						
					case 2: // Mountpoint type. Example ext4
						m_type = lstr;
						
					case 3: // Mountpoint options. Example rw,relatime,errors=remount-ro
						m_options = lstr;
						
					case 4: // Mountpoint dump option. Example 0
						m_dump = lstr;
						
					case 5: // Mountpoint pass option. Example 1
						m_pass = lstr;
						break;
						
					default:
						fprintf(stderr, "Reading stage unknown value! Value: %d - FILE %s @ %d", stage, __FILE__, __LINE__);
						break;
					}
					++stage;
				} while(stage != 6);
				
				// Writing new file stage
		        fprintf(stdout, "%s		%s			%s	%s	%s	%s\n", m_dev, m_mountpoint, m_type, m_options, m_dump, m_pass);
			}
		}
		
		write_str("\n", stdout);
		//fclose(outf);
		//outf = NULL;
		fclose(f);
		f = NULL;
	}
	else
	{
		fprintf(stderr, "Fail to open /proc/mounts for reading!");
		return 1;
	}
	
	return 0;
}


