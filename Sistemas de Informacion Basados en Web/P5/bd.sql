-- Creacion de la tabla --

CREATE TABLE eventos (
    nombre VARCHAR(100),
    publicado BOOLEAN
);

-- Cambiar los permisos para poder alterar desde el root --
GRANT ALTER ON SIBW.* TO 'alvaro'@'%';

-- Añadir una nueva columna a una tabla ya creada --
ALTER TABLE eventos ADD COLUMN id INT AUTO_INCREMENT PRIMARY KEY;

SELECT * FROM eventos WHERE nombre LIKE '%es%';

-- Consulta para seleccionar los eventos publicados --
SELECT * FROM eventos WHERE publicado=1;