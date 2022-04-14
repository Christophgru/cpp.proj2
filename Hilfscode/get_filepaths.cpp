//
// Created by chris on 4/14/2022.
//
tinydir_dir dir;
tinydir_open(&dir, "/path/to/dir");

while (dir.has_next)
{
tinydir_file file;
tinydir_readfile(&dir, &file);

printf("%s", file.name);
if (file.is_dir)
{
printf("/");
}
printf("\n");

tinydir_next(&dir);
}

tinydir_close(&dir);